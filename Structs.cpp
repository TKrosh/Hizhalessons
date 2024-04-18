#define SIZE 50

struct Tree{
    char elem;

    Tree *left, *right;
};

struct tree_queue{
    int begin = 0, end = -1;
    Tree* nums[SIZE];
};

