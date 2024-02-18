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

void save(float num)
{
    FILE* file2;
    fopen_s(&file2, "output.txt", "w");
    fprintf(file2, "%f", num);
    fclose(file2);
}

void calculate(list* n, list* s)
{
    float sum = 0;
    list* x, * y;
    x = s;
    y = n;
    while (x->next != NULL)
    {
        sum += (x->elem) * (y->elem);
        x = x->next;
        y = y->prev;
    };
    sum += (x->elem) * (y->elem);
    save(sum);
    clean(s);
}

void check(list* n)
{
    while (n->next != NULL)
    {
        printf("%f", n->elem);
        printf(" ");
        n = n->next;
    };
    printf("%f", n->elem);
}

void input()
{
    FILE* file1;
    fopen_s(&file1, "input.txt", "r");
    char c = ' ';


    if (!file1)
    {
        printf("ERROR!!! FILE DOES NOT FOUNDED");
        exit(1);
    }

    list* n, * t, * s;
    s = new list;
    n = s;
    s->prev = NULL;
    fscanf_s(file1, "%f", &n->elem);
    printf("%c", c);
    printf("%c", n->elem);

    while (c != EOF)
    {
        t = new list;
        t->prev = n;
        n->next = t;
        n = n->next;
        fscanf_s(file1, "%f", &t->elem);
        c = fgetc(file1);
    };
    n->next = NULL;
    calculate(n, s);
    fclose(file1);

}


int main()
{
    input();
}