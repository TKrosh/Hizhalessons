#include <stdio.h>
#include "queue.cpp"


struct list{
    float elem;
    list* next;
};

void show(queue queue1){
    queue queue2;
    float c;
    create_queue(&queue2);
    while(!is_empty(queue1)){
        c = pop(&queue1);
        printf("%f ", c);
        push(&queue2, c);
    }
    while(!is_empty(queue2)){
        c = pop(&queue2);
        push(&queue1, c);
    }
}

int calculate(char* file_name, list** output_list){
    queue element_in_range, element_out_range;
    float a, b;

    FILE* input_file = fopen(file_name, "r");
    list* position;
    char c = ' ';

    if (!input_file)
        return 1;

    fscanf(input_file, "%f", &a);
    fscanf(input_file, "%f", &b);


    list *head = new list;
    position = head;
    fscanf(input_file, "%f", &position -> elem);
    c = fgetc(input_file);

    while (c != EOF){
        position -> next = new list;
        position = position -> next;
        fscanf(input_file, "%f", &position -> elem);
        c = fgetc(input_file);
    }
    position -> next = NULL;


    create_queue(&element_in_range);
    create_queue(&element_out_range);

    list* current = head, *cr_position;
    *output_list = new list;
    cr_position = *output_list;


    while(current != NULL){

        if (current -> elem < a){
            cr_position -> elem = current -> elem;
            cr_position -> next = new list;
            cr_position = cr_position -> next;
        }

        else if( (current -> elem >= a) && (current -> elem <= b))
            push(&element_in_range, current->elem);

        else
            push(&element_out_range, current->elem);

        current = current -> next;
    }

    show(element_in_range);
    show(element_out_range);
    while (!is_empty(element_in_range)){
        cr_position -> elem = pop(&element_in_range);
        cr_position -> next = new list;
        cr_position = cr_position -> next;
    }
    while (!is_empty(element_out_range)){
        cr_position-> elem = pop(&element_out_range);
        cr_position -> next = new list;
        cr_position = cr_position -> next;
    }


    position = NULL;
    fclose(input_file);
    return 0;

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
    int c;
    c = calculate(input_file_name, &output_list);
        if (c) {
        printf("0");
        return 0;
    }
    output(output_list, output_file_name);

}