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
    fprintf(file2, "%.3f", num);
    fclose(file2);
}

float calculate(list* s)
{
    float sum = 0;
    list* x, * y;
    x = s;
    y = s -> prev;
    while ((x != y) && (y -> next != x))
    {

        sum += 2 * (x->elem) * (y->elem);
        x = x->next;
        y = y->prev;
    };
    if (x == y)
        sum += (x->elem) * (y->elem);

    return sum;
}

//void check(list* n)
//{
// while (n->next != NULL)
// {
// printf("%f\n", n->elem);
// n = n->next;
// }
// printf("%f", n->elem);
//}

void input(list* s)
{
    FILE* file1 = fopen("input.txt", "r");
    list* n, * t;
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
    }

    n->next = NULL;
    s -> prev = n;
    fclose(file1);

}

int main(void){
    list* s = new list;
    float sum;
    input(s);
// check(s);
    sum = calculate(s);
    save(sum);
    clean(s);
    return 0;
}