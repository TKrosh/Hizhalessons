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





int input(char *fname, list** s)
{
    FILE* file1 = fopen(fname, "r");;
    list* t, *n;
    char c = ' ';

    if (!file1)
    {
        return 1;
    }
    *s = new list;
    n = *s;
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
    (*s)->prev = n;
    n->next = NULL;
    fclose(file1);

    return 0;
}


int main()
{
    list* s;
    int c;
    float sum;


    char fname[] = "input.txt";

    c = input(fname, &s);
    if(c) {
        printf("0");
        return -1;
    }
    sum = calculate(s);
    save(sum);
    clean(s);
    return 0;
};
