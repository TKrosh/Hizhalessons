#include <stdio.h>
#include <string.h>


const int N = 16;


struct info
{
    int hash_code;
    char code[9];
    char name[50];
    int amount;
    float price;
};


struct table
{
    info el[N];
};


int appending_table(table* work_result, char* test_name, char* prices) {
    FILE* input_file = fopen(test_name, "r");
    FILE* price_file;
    info element_of_table, good_price;
    int i = 0;

    if(!input_file)
        return 1;

    while(fscanf(input_file, "%d %s %s %d", &element_of_table.hash_code, element_of_table.code, element_of_table.name, &element_of_table.amount) != EOF){
        price_file = fopen(prices, "r");

        if(!price_file)
            return 1;

        strcpy(good_price.code, "");

        while(fscanf(price_file, "%s %f", good_price.code, &good_price.price) != EOF && strcmp(element_of_table.code, good_price.code) >= 0){
            if (!strcmp(element_of_table.code, good_price.code)){
                work_result->el[i] = element_of_table;
                work_result->el[i++].price = good_price.price;
            }
        }
    }
    for(int j = 0; j < i; j++){
        info x = work_result->el[j];
        printf("%d %s %s %d %f\n", x.hash_code, x.code, x.name, x.amount, x.price);
    }
    fclose(input_file);
    fclose(price_file);
    return 0;
}

void sorting_table();


int main(){
    table result;
    int task_completed;
    char test_name[] = "test1.txt";
    char prices[] = "price_list.txt";
    task_completed = appending_table(&result, test_name, prices);
    if (task_completed){
        printf("sadfgbfdsdsfghgdchn");
        return 1;
    }

}