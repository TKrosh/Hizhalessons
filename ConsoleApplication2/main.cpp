#include <stdio.h>
#include <stdlib.h>

struct word
{
    word* next = NULL;
    char letter;
};

struct dict
{
    dict* next = NULL;
    word* first_letter;
};

struct list
{
    list* next = NULL;
    int n = 0;
};

int input(char* file_name, dict** book_start)
{
    FILE* input_file;
    word* slovo;
    dict* book;
    book = *book_start;
    char c;

    fopen_s(&input_file, file_name, "r");
    if (!input_file)
        return 0;
    c = fgetc(input_file);
    slovo = new word;
    slovo->letter = c;
    book->first_letter = slovo;
    c = fgetc(input_file);
    while (c != '.')
    {
        if (c == ',')
        {
            slovo->next = NULL;
            book->next = new dict;
            book = book->next;
            c = fgetc(input_file);
            slovo = new word;
            slovo->letter = c;
            book->first_letter = slovo;
        }
        else
        {
            slovo->next = new word;
            slovo = slovo->next;
            slovo->letter = c;
        }
        c = fgetc(input_file);
    }
    fclose(input_file);
    return 1;
}

int check_len(dict** book_start, list* lens)
{
    int count, max = -1;
    word* slovo;
    dict* book;
    list* len_words;
    len_words = lens;
    book = *book_start;

    while (book->next != NULL)
    {
        count = 0;
        slovo = book->first_letter;
        while (slovo->next != NULL)
        {
            count++;
            slovo = slovo->next;
        }
        book = book->next;
        if (count > max) max = count;
        len_words->n = count;
        len_words->next = new list;
        len_words = len_words->next;
    }
    count = 0;
    slovo = book->first_letter;
    while (slovo->next != NULL)
    {
        count++;
        slovo = slovo->next;
    }
    len_words->n = count;
    if (count > max) max = count;
    return max;
}

void save(dict** book_start, list* lens, int max)
{
    dict* book;
    book = *book_start;
    list* len_words;
    len_words = lens;
    word* slovo;

    FILE* output_file;
    fopen_s(&output_file, "result.txt", "w");

    while (book->next != NULL)
    {
        if (len_words->n == max)
        {
            slovo = book->first_letter;
            while (slovo->next != NULL)
            {
                fprintf(output_file, "%c", slovo->letter);
                slovo = slovo->next;
            }
            fprintf(output_file, "%c", slovo->letter);
            fprintf(output_file, "\n");
        }
        len_words = len_words->next;
        book = book->next;

    }
    if (len_words->n == max)
    {
        slovo = book->first_letter;
        while (slovo->next != NULL)
        {
            fprintf(output_file, "%c", slovo->letter);
            slovo = slovo->next;
        }
        fprintf(output_file, "%c", slovo->letter);
    }


    fclose(output_file);
}

int main() {
    int c, max;
    char input_file_name[] = "words.txt";
    dict* book_start;
    list* len_words;
    len_words = new list;
    book_start = new dict;

    c = input(input_file_name, &book_start);
    if (!c)
    {
        printf("0");
        return 0;
    }
    max = check_len(&book_start, len_words);
    save(&book_start, len_words, max);
    return 0;
}