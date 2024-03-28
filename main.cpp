#include <stdio.h>
#include "queue.cpp"


struct list{
    float elem;
    list* next;
};

int input(list** head, char* file_name, float* a, float* b){
    FILE* input_file = fopen(file_name, "r");
    list* position;
    char c = ' ';

    if (!input_file)
        return 1;

    fscanf(input_file, "%f", &*a);
    fscanf(input_file, "%f", &*b);


    *head = new list;
    position = *head;
    fscanf(input_file, "%f", &position -> elem);
    c = fgetc(input_file);

    while (c != EOF){
        position -> next = new list;
        position = position -> next;
        fscanf(input_file, "%f", &position -> elem);
        c = fgetc(input_file);
    }
    position -> next = NULL;


    fclose(input_file);
    return 0;
}

void pop_and_add_to_list(queue queue, list** position){
    while (!is_empty(queue)){
        (*position) -> elem = pop(&queue);
        (*position) -> next = new list;
        (*position) = (*position) -> next;
    }
}

void calculate(list* input_list, list** output_list, float a, float b){
    queue element_in_range, element_out_range;
    create_queue(&element_in_range);
    create_queue(&element_out_range);

    list* current = input_list, *position;
    *output_list = new list;
    position = *output_list;


    while(current != NULL){

        if (current -> elem < a){
            position -> elem = current -> elem;
            position -> next = new list;
            position = position -> next;
        }

        else if( (current -> elem >= a) && (current -> elem <= b))
            push(&element_in_range, current->elem);

        else
            push(&element_out_range, current->elem);

        current = current -> next;
    }

    pop_and_add_to_list(element_in_range, &position);
    pop_and_add_to_list(element_out_range, &position);
    position = NULL;


}


int output(list* output_list, char* file_name){
    FILE* output_file = fopen(file_name, "w");
    if (!output_list){
        return 1;
    }

    for (list* element = output_list; element -> next != NULL; element = element -> next)
        fprintf(output_file, "%.4f ", element -> elem);

    fclose(output_file);
    return 0;
}




int main() {
    list* input_list, *output_list;
    char input_file_name[] = "input.txt";
    char output_file_name[] = "output.txt";
    float a, b;
    int c, d;

    c = input(&input_list, input_file_name, &a, &b);
    if (c) {
        printf("0");
        return 0;
    }
    calculate(input_list, &output_list, a, b);
    output(output_list, output_file_name);

}