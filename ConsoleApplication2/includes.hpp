#pragma once

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

void binsort(table* n, int start, int end);
void check_table(table* n);
void biuld_tree(table* nums);
