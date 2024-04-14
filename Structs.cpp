#include <stdio.h>
#define SIZE 50

struct Tree{
    char elem;
    int level;
    Tree *left, *right;
};

struct queue{
    int begin = 0, end = -1;
    Tree* nums[SIZE];
};
