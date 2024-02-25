#include <stdio.h>
#include <stdlib.h>

struct node{
    node *next = NULL, *prev = NULL;
    float element = 0;
};

struct list{
    node* head = NULL;
    node* tail = NULL;
};



void nodecreate(node* p, float num){
    node *n = new node;
    n -> element = num;
    n -> prev = p;
    p -> next = n;
}


void input(list* h){

    float element;
    node* p;
    FILE* input_file = fopen("input.txt", "r");
    char c = ' ';

    if (!input_file){
        printf("Ошибка открытия файла");
        exit(1);
    }
    h -> head = new node;

    p = h -> head;
    fscanf(input_file, "%f", &p -> element);

    while(c != EOF)
    {
        fscanf(input_file, "%f", &element);
        nodecreate(p, element);
        p = p -> next;
        c = fgetc(input_file);
    }
    h -> tail = p;
    fclose(input_file);

}

float sequence(node *h, node *p)
{
    float sum = 0;
    node *x = h, *y = p;
    while((x != y) && (x -> prev != y))
    {
        sum += 2 * (x -> element) * (y -> element);
        x = x -> next;
        y = y -> prev;

    }
    if (x == y)
        sum += (x -> element) * (y -> element);
    return sum;
}

void output(float sum)
{
    FILE* output_file = fopen("out.txt", "w");

    if(!output_file)
    {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fprintf(output_file, "%.3f", sum);

    fclose(output_file);

}

void Delete(node *l)
{
    node *k = l -> next;
    for(; k; k = k-> next){
        delete l;
        l = k;
    }
    delete l;

}

int main(){
    list *n;
    node *p, *h;
    float a;
    input(n);
    h = n -> head;
    p = n -> tail;
    a = sequence(h, p);
    output(a);
    Delete(h);
    return 0;
}