#include <stdio.h>
#include "Queue.cpp"


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
    queue tree_queue;
    Tree* current_tree_element;
    int prev_level;
    tree -> level = 0;
    current_tree_element = tree;
    push(&tree_queue, tree);
    do {
        prev_level = current_tree_element -> level;
        show(&tree_queue);
        current_tree_element = pop(&tree_queue);
        if (current_tree_element -> level != prev_level)
            fprintf(output_file, "\n");
        fprintf(output_file, "%c ", current_tree_element -> elem);
        if (current_tree_element -> left != NULL) {
            current_tree_element -> left -> level = current_tree_element -> level + 1;
            push(&tree_queue, current_tree_element -> left);
        }
        if (current_tree_element -> right != NULL) {
            current_tree_element -> right -> level = current_tree_element -> level + 1;
            push(&tree_queue, current_tree_element -> right);
        }
    }
    while (!is_empty(tree_queue));
}

int main(){
    Tree* tree;
    FILE* input_file = fopen("input.txt", "r");
    tree = build_tree(input_file);
    BFS(tree, "output.txt");
}