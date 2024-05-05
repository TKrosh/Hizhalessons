#include "stdio.h"
#include "string.h"

const int N = 256;

struct info
{
    char code[9];
    char name[50];
    int amount;
};


struct table
{
    info* el[N];
    int n = 0;
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

int raise(int q)
{
    int num = 1;
    for (int i = 1; i <= q; i++)
    {
        num *= 2;
    }

    return num;
}


int heshing(char code[9], int col = 0)
{
    int i;
    int sum = 0;
    for (i = 0; i < 8; i++)
    {
        sum += (code[i] - 0) * raise(i);
    }
    sum = (sum + col) % N;
    return sum;
}

int rehash(int hash, table* t, info* elem)
{
    int new_hash; //that is a new hash
    new_hash = (hash + 1) % N;
    while (t->el[new_hash] && hash != new_hash && strcmp(t->el[new_hash]->code, elem->code))
    {
        new_hash = (new_hash + 1) % N;
    }
    return new_hash;
}

void output(char* output_file_name, table* result) {
    FILE* output_file = fopen(output_file_name, "w");;
    info* elem;
    for (int i = 0; i < N; i++)
    {
        elem = result->el[i];
        if (result->el[i]) fprintf(output_file, "%d %s %s %d\n", i, elem->code, elem->name, elem->amount);

    }
    fclose(output_file);
}

int build_the_table(char* input_file_name, table* Work_result)
{
    FILE* input_file = fopen(input_file_name, "r");;
    info elem;
    int hash, new_hash, res = 1;

    if (!input_file)
        return 0;

    for(int i = 0; i < N; i++)
        Work_result->el[i] = NULL;


    while (fscanf(input_file, "%s %s %d", elem.code, elem.name, &elem.amount) != EOF)
    {
        hash = heshing(elem.code);
//        printf("%d\n", hash);
        if (!Work_result->el[hash])
        {
            Work_result->el[hash] = new info;
            *Work_result->el[hash] = elem;
            Work_result->n = Work_result->n + 1;
        }
        else
        {

            if (!strcmp(Work_result->el[hash]->code, elem.code))
            {
                Work_result->el[hash]->amount += elem.amount;
            }
            else
            {
                
                new_hash = rehash(hash, Work_result, &elem);
                if (hash == new_hash)
                {
                    res = 0;// if there is "return" we won't work with ements
                    //that is in the table, but goes after elem that does not have palce
                    //in the table
                }
                if (!Work_result->el[new_hash])
                {
                    Work_result->el[new_hash] = new info;
                    *Work_result->el[new_hash] = elem;
                    Work_result->n = Work_result->n + 1;
                }
                else
                {
                    Work_result->el[new_hash]->amount += elem.amount;
                }
            }
        }

        //check(Work_result);
    }

    fclose(input_file);
    return res ? 1: -1;


};

int main() {
    int c;
    table Work_result;

    c = build_the_table("test.txt", &Work_result);
    if (!c)
    {
        printf("0");
        return 0;
    }
    output("result.txt", &Work_result);
    if (c == -1)
    {
        printf("-1"); //too mush elements, no place in table!!!
        return 0;
    }

    return 0;
}