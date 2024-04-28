#include <stdio.h>
#include <stdlib.h>

const int N = 250;

struct info
{
    char code[9];
    char name[50];
    int amount;
};


struct table
{
    info* el[N];
};

void check(table* tab)
{
    info* elem;
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        elem = tab->el[i];
        if (elem != NULL) printf("%d) %s %s %d\n", i, elem->code, elem->name, elem->amount);

    }
}

int raise(int q) // возведение в степень, чтобы каждой позиции дать вес, используется основание 2
// ибо 10 слишком много
{
    int num = 1;
    for (int i = 1; i <= q; i++)
    {
        num *= 2;
    }

    return num;
}


int heshing(char code[9])
{
    int i;
    int sum = 0;
    for (i = 0; i < 8; i++)
    {
        sum += (code[i] - 0) * raise(i);
    }
    sum = (sum) % N;
    return sum;
}

int build_the_table(char* input_file_name)
{
    table Work_result;
    for (int i = 0; i < N; i++)
    {
        Work_result.el[i] = NULL;
    }

    FILE* input_file;
    info elem;
    int hash;


    fopen_s(&input_file, "test.txt", "r");
    if (!input_file)
        return 1;
    while (fscanf_s(input_file, "%s %s %d", elem.code, _countof(elem.code), elem.name, _countof(elem.name), &elem.amount) != EOF)
    {
        hash = heshing(elem.code); //значится, захешили
        printf("%d ", hash);
        //проверочка на наличие в таблице?
        if (!Work_result.el[hash]) Work_result.el[hash] = &elem;

        check(&Work_result);
    }

    //printf("%s %s %d\n", Work_result.el[113]->code, Work_result.el[113]->name, Work_result.el[113]->amount);

    fclose(input_file);
};

int main() {
    int c;
    char input_file_name[] = "test.txt";

    c = build_the_table(input_file_name);
    if (c) {
        printf("0");
        return 0;
    }

    return 0;
}