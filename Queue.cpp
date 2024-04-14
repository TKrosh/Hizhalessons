#include <stdio.h>
#include "Structs.cpp"



int push(queue* queue, Tree* tree){
    queue -> end = (queue -> end + 1) % SIZE;
    queue -> nums[queue -> end] = tree;
    return 1;
}


int is_empty(queue queue){
    return queue.end == queue.begin - 1;
}


Tree* pop(queue* queue){
    Tree* element = queue -> nums[queue -> begin];
    if(queue -> begin == queue -> end){
        queue -> begin = 0;
        queue -> end = -1;
    }
    else
        queue -> begin = (queue -> begin + 1) % SIZE;
    return element;
}


void show(queue* queue1){
    queue queue2;
    Tree* c;
    while(!is_empty(*queue1)){
        c = pop(queue1);
        printf("%c ", c -> elem);
        push(&queue2, c);
    }
    while(!is_empty(queue2)){
        c = pop(&queue2);
        push(queue1, c);
    }
    printf("\n");
}






