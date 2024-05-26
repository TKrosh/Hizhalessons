#include <stdio.h>
#include <string.h>
#include "includes.hpp"


void check_table(table* n)
{
	for (int i = 0; i < N; i++)
	{
		info x = n->el[i];
		if (strcmp(x.code, ""))
		{
			printf("%d %s %s %d %f\n", x.hash_code, x.code, x.name, x.amount, x.price);
		}

	}
	printf("\n");
}

void binsort(table* n, int start, int end)
{
	info x;
	int t, lt, rt, max;
	max = start;
	do
	{
		t = max;
		lt = 2 * t + 1;
		rt = 2 * (t + 1);
		if (lt <= end)
			if (n->el[lt].amount > n->el[t].amount)
				max = lt;
		if (rt <= end)
			if (n->el[rt].amount > n->el[max].amount)
				max = rt;
		x = n->el[t];
		n->el[t] = n->el[max];
		n->el[max] = x;
	} while (t != max);
}

void biuld_tree(table* nums)
{
	info x;
	for (int i = (N - 1) / 2; i >= 0; i--)
	{
		binsort(nums, i, N - 1);
	}
	printf("\n");
	for (int i = (N - 1); i > 0; i--)
	{
		x = nums->el[0];
		nums->el[0] = nums->el[i];
		nums->el[i] = x;
		binsort(nums, 0, i - 1);
	}
}
