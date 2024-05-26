#include <stdio.h>
#include <string.h>

void binsort(int* n, int start, int end)
{
	int t, lt, rt, max, x;
	max = start;
	do
	{
		t = max;
		lt = 2 * t + 1;
		rt = 2 * (t + 1);
		if (lt <= end)
			if (n[lt] > n[t])
				max = lt;
		if (rt <= end)
			if (n[rt] > n[max])
				max = rt;
		x = n[t];
		n[t] = n[max];
		n[max] = x;
	} while (t != max);
}

void check(int* n)
{
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", n[i]);
	}
	printf("\n");
}

int main() {
	int x;
	int nums[8] = { 58, 6, 46, 4, 45, 455, 19, 7 };
	int copy_nums[8] = { 58, 6, 46, 4, 45, 455, 19, 7 };

	for (int i = (8 - 1) / 2; i >= 0; i--)
	{
		binsort(nums, i, 8 - 1);
		check(nums);
	}
	printf("\n");
	for (int i = (8 - 1); i > 0; i--)
	{
		x = nums[0];
		nums[0] = nums[i];
		nums[i] = x;
		binsort(nums, 0, i - 1);
		check(nums);
	}
	printf("The input: ");
	check(copy_nums);
	printf("The output: ");
	check(nums);
	return 0;
}