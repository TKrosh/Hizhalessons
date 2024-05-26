#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.hpp"



int appending_table(table* work_result, char* test_name, char* prices) {
    FILE* input_file;
    FILE* price_file;

    fopen_s(&price_file, prices, "r");
    fopen_s(&input_file, test_name, "r");
    info element_of_table, good_price;
    int i = 0;
    if (!input_file)
        return 1;

    for (int i = 0; i < N; i++)
    {
        strcpy_s(work_result->el[i].code, "");
    }


    while (fscanf_s(input_file, "%d %s %s %d", &element_of_table.hash_code, element_of_table.code, _countof(element_of_table.code), element_of_table.name, _countof(element_of_table.code), &element_of_table.amount) != EOF)
    {

        if (!price_file)
            return 1;


        while (fscanf_s(price_file, "%s %f", good_price.code, _countof(good_price.code), &good_price.price) != EOF && strcmp(element_of_table.code, good_price.code) >= 0) {
            if (!strcmp(element_of_table.code, good_price.code)) {
                work_result->el[i] = element_of_table;
                work_result->el[i++].price = good_price.price;
            }
        }
        fseek(price_file, 0, SEEK_SET);
    }

    fclose(input_file);
    fclose(price_file);
    return 0;
}


void output(char* output_file_name, table* result) {
    FILE* output_file;
    info elem;
    fopen_s(&output_file, output_file_name, "w");
    for (int i = 0; i < N; i++)
    {
        elem = result->el[i];
        if (strcmp(elem.code, ""))
            fprintf(output_file, "%d %d %s %s %d\n", i, elem.hash_code, elem.code, elem.name, elem.amount);
    }
    fclose(output_file);
}


int main() {
    table result;
    int task_completed;
    char test_name[] = "test1.txt";
    char prices[] = "price_list.txt";
    char output_file[] = "output.txt";
    task_completed = appending_table(&result, test_name, prices);
    if (task_completed) {
        printf("0");
        return 1;
    }

    biuld_tree(&result);
    check_table(&result);
    output(output_file, &result);
}