#include <stdio.h>
#include "Tree_queue.cpp"


Tree* build_tree(FILE* input_file){
    char sym;
    Tree* d;
    fscanf(input_file, "%c", &sym);
    switch (sym) {
        case '(': {
            d = new Tree;
            fscanf(input_file, "%c", &sym);
            d->elem = sym;
            d->left = build_tree(input_file);
            d->right = build_tree(input_file);
            fscanf(input_file, "%c", &sym);
            return d;
        }
        case '0': return NULL;
        case ',': return build_tree(input_file);
        case ' ': return build_tree(input_file);
    }
    return NULL;
}


void BFS(Tree* tree, char* output_file_name){
    FILE* output_file = fopen(output_file_name, "w");
    tree_queue tree_queue;
    int k = 1, l;
    Tree* current_tree_element;
    push(&tree_queue, tree);

    do {
        l = 0;
        show(&tree_queue);
        do {
            current_tree_element = pop(&tree_queue);
            fprintf(output_file, "%c ", current_tree_element -> elem);
            if (current_tree_element -> left != NULL) {
                push(&tree_queue, current_tree_element->left);
                l++;
            }

            if (current_tree_element -> right != NULL) {
                push(&tree_queue, current_tree_element->right);
                l++;
            }
            k--;
        }
        while (k != 0);
        fprintf(output_file, "\n");
        k = l;
    }
    while (k != 0);
}

int main(){
    Tree* tree;
    FILE* input_file = fopen("input.txt", "r");
    if (!input_file){
        printf("NO FILE!");
        return 1;
    }
    tree = build_tree(input_file);
    BFS(tree, "output.txt");
    return 0;
}