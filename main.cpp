#include "stdio.h"
#include "string.h"

const int N = 16;

struct info
{
    char code[9];
    char name[50];
    int amount;
};


struct table
{
    info el[N];
};

//void check(table* tab)
//{
//    info elem;
//    printf("\n");
//    for (int i = 0; i < N; i++)
//    {
//        elem = tab->el[i];
//        if (elem != NULL) printf("%d) %s %s %d\n", i, elem->code, elem->name, elem->amount);
//
//    }
//}

int pow(int q)
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
        sum += (code[i] - 0) * pow(i);
    }
    sum = (sum + col) % N;
    return sum;
}

int rehash(int hash, table* t, info* elem)
{
    int new_hash; //that is a new hash
    new_hash = (hash + 1) % N;
    while (strcmp(t->el[new_hash].code, "") && hash != new_hash && strcmp(t->el[new_hash].code, elem->code))
    {
        new_hash = (new_hash + 1) % N;
    }
    return new_hash;
}

void output(char* output_file_name, table* result) {
    FILE* output_file = fopen(output_file_name, "w");;
    info elem;
    for (int i = 0; i < N; i++)
    {
        elem = result->el[i];
        if (strcmp(elem.code, ""))

            fprintf(output_file, "%d %d %s %s %d\n", i, heshing(elem.code), elem.code, elem.name, elem.amount);


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
    {

        strcpy(Work_result->el[i].code, ""); // !!!!!!!!!!!!!!!!

    }


    while (fscanf(input_file, "%s %s %d", elem.code, elem.name, &elem.amount) != EOF && res)
    {
        hash = heshing(elem.code);
        if (!strcmp(Work_result->el[hash].code, ""))

            Work_result ->el[hash] = elem;
        else
        {

            if (!strcmp(Work_result->el[hash].code, elem.code))
                Work_result->el[hash].amount += elem.amount;
            else
            {
                
                new_hash = rehash(hash, Work_result, &elem);
                if (hash == new_hash)
                    res = 0;

                if (!strcmp(Work_result->el[new_hash].code, ""))
                    Work_result ->el[new_hash] = elem;


                else
                    Work_result->el[new_hash].amount += elem.amount;

            }
        }

        //check(Work_result);
    }

    fclose(input_file);
    return res;


};

int main() {

    int c;
    table Work_result;

    c = build_the_table("test4.txt", &Work_result);
    if (!c)
    {
        printf("0");
        return 0;
    }

    output("result.txt", &Work_result);

    return 0;
}