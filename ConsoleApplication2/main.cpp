#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int new_hash; //переменная для нового хеша
    new_hash = (hash + 1) % N;
    while (t->el[new_hash] && hash != new_hash && strcmp(t->el[new_hash]->code, elem->code))
    {
        new_hash = (new_hash + 1) % N;
    }
    return new_hash;
}

int build_the_table(char* input_file_name, table* Work_result)
{
    FILE* input_file;
    info elem;
    int hash;

    for (int i = 0; i < N; i++)
    {
        Work_result->el[i] = NULL;
    }


    fopen_s(&input_file, input_file_name, "r");
    if (!input_file)
        return 1;


    while (fscanf_s(input_file, "%s %s %d", elem.code, _countof(elem.code), elem.name, _countof(elem.name), &elem.amount) != EOF)
    {
        hash = heshing(elem.code); //значится, захешили
        printf("%d ", hash);
        //проверочка на наличие в таблице?
        if (!Work_result->el[hash])
        {//если с списках не значиться, то добавить
            Work_result->el[hash] = new info;
            *Work_result->el[hash] = elem;
        }
        else//теперь проверяем произощло ли совпадение хешей или это тот же товар
        {

            if (!strcmp(Work_result->el[hash]->code, elem.code))//если этот товар уже есть то увеличиваем кол-во
            {
                Work_result->el[hash]->amount += elem.amount;
            }
            else
            {
                hash = rehash(hash, Work_result, &elem);
                if (!Work_result->el[hash])//если этот товар уже есть то увеличиваем кол-во
                {
                    Work_result->el[hash] = new info;
                    *Work_result->el[hash] = elem;
                }
                else
                {
                    Work_result->el[hash]->amount += elem.amount;
                }
            }
        }

        check(Work_result);
    }

    fclose(input_file);
};

int main() {
    int c;
    char input_file_name[] = "test.txt";
    table Work_result;

    c = build_the_table(input_file_name, &Work_result);
    if (c) {
        printf("0");
        return 0;
    }

    return 0;
}