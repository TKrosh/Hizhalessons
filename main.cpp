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
    push(&tree_queue, tree);
    do {
        show(&tree_queue);
        current_tree_element = pop(&tree_queue);
        fprintf(output_file, "%c ", current_tree_element -> elem);
        if (current_tree_element -> left != NULL) push(&tree_queue, current_tree_element -> left);
        if (current_tree_element -> right != NULL) push(&tree_queue, current_tree_element -> right);
    }
    while (!is_empty(tree_queue));
}

int main(){
    Tree* tree;
    FILE* input_file = fopen("input.txt", "r");
    tree = build_tree(input_file);
    BFS(tree, "output.txt");
}