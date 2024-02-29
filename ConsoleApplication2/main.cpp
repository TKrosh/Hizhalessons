#include <stdio.h>
#include <stdlib.h>

struct list
{
    list* next, * prev;
    float elem;
};

void clean(list* s)
{
    list* k = s->next;
    for (; k; k = k->next)
    {
        delete s;
        s = k;
    }
    delete s;
}
/*
void check(list* n)
{
    while (n->next != NULL)
    {
        printf("%f", n->elem);
        printf(" ");
        n = n->next;
    };
    printf("%f", n->elem);
}*/

void save(float num)
{
    FILE* file2 = fopen("output.txt", "w");
    fprintf(file2, "%f", num);
    fclose(file2);
}

float calculate(list* s)
{
    float sum = 0;
    list* x, * y;
    x = s;
    y = s->prev;
    while ((y->next != x) && (x != y))
    {
        sum = sum + 2 * (x->elem) * (y->elem);
        x = x->next;
        y = y->prev;
    };
    if (x == y)
    {
        sum = sum + (x->elem) * (y->elem);
    }
    return sum;
}

void input(char *fname, list* s)
{
    FILE* file1 = fopen(fname, "r");;
    list* t, *n;
    char c = ' ';

    if (!file1)
    {
        printf("ERROR!!! FILE DOES NOT FOUNDED");
        exit(1);
    }


    n = s;
    fscanf(file1, "%f", &n->elem);

    while (c != EOF)
    {
        t = new list;
        t->prev = n;
        n->next = t;
        n = n->next;
        fscanf(file1, "%f", &t->elem);
        c = fgetc(file1);
    };
    s->prev = n;
    n->next = NULL;
    fclose(file1);
}


int main()
{
    list* s;
    float sum;
    s = new list;

    char fname[] = "input.txt";

    input(fname, s);
    sum = calculate(s);
    save(sum);
    clean(s);
    return 0;
};
