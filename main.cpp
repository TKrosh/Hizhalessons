#include <stdio.h>
#include <string.h>
#include <math.h>

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
        if (tab->el[i]) printf("%d) %s %s %d\n", i, elem->code, elem->name, elem->amount);

    }
}

void rehash(table* tab, int* hash){
    while(tab->el[*hash]) *hash = (*hash + 1) % N;

}


int heshing(char* code){
    int i;
    int sum = 0;
    for (i = 0; i < 8; i++)
    {
        sum += (code[i] - 0) * pow(2, i);
    }
    sum = (sum) % N;
    return sum;
}

int build_the_table(char* input_file_name, table* Work_result)
{
    FILE* input_file = fopen(input_file_name, "r");;
    info elem;
    int hash;

    if (!input_file)
        return 1;

    for (int i = 0; i < N; i++)
    {
        Work_result->el[i] = NULL;

    }

    while (fscanf(input_file, "%s %s %d", elem.code, elem.name, &elem.amount) != EOF)
    {
        hash = heshing(elem.code); //значится, захешили
//        printf("%d %s %s ", hash, elem.code, elem.name);
        if (!Work_result->el[hash]){
            Work_result->el[hash] = new info;
            *Work_result->el[hash] = elem;
        }
        else if (!strcmp(Work_result->el[hash]->code, elem.code))
            Work_result->el[hash]->amount += elem.amount;
        else {
            rehash(Work_result, &hash);
            Work_result->el[hash] = new info;
            *Work_result->el[hash] = elem;
        }



    }

    fclose(input_file);
    return 0;
}


void output(char* output_file_name, table* result){
    FILE* output_file = fopen(output_file_name, "w");
    info* elem;
    for (int i = 0; i < N; i++)
    {
        elem = result->el[i];
        if (result->el[i]) fprintf(output_file, "%d) %s %s %d\n", i, elem->code, elem->name, elem->amount);

    }

}

int main() {
    int c;
    table table;

    c = build_the_table("input.txt", &table);
    if (c) {
        printf("0");
        return 1;
    }
    output("output.txt", &table);
    return 0;
}