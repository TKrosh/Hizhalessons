#include <stdio.h>
#include <stdlib.h>

struct runner
{
	int num = 0;
	float time = 0;
};

struct table
{
	runner el[3];
};

int find_win(char* file_name, table* winners)
{
	FILE* input_file;
	fopen_s(&input_file, file_name, "r");

	if (!input_file)
	{
		return 0;
	}

	int number;
	float start, finish, time;

	while (fscanf_s(input_file, "%d %f %f", &number, &start, &finish) != EOF)
	{
		time = finish - start;
		if ((time <= winners->el[0].time) || (winners->el[0].time == 0))
		{
			winners->el[2] = winners->el[1];
			winners->el[1] = winners->el[0];
			winners->el[0].num = number;
			winners->el[0].time = time;
		}
		else if ((time <= winners->el[1].time) || (winners->el[1].time == 0))
		{
			winners->el[2] = winners->el[1];
			winners->el[1].num = number;
			winners->el[1].time = time;
		}
		else if ((time <= winners->el[2].time) || (winners->el[2].time == 0))
		{
			winners->el[2].num = number;
			winners->el[2].time = time;
		}
	}
	return 1;
}

void save(char* file_name, table* winners)
{
	FILE* output_file;
	fopen_s(&output_file, file_name, "w");
	if (winners->el[2].num == 0) fprintf(output_file, "\n");
	else for (int i = 0; i < 3; i++) fprintf(output_file, "%d %f\n", winners->el[i].num, winners->el[i].time);

}

int main()
{
	table winners;
	char input_file_name[] = "input.txt";
	char output_file_name[] = "result.txt";
	int c;
	c = find_win(input_file_name, &winners);
	if (!c)
	{
		printf("0");
		return 0;
	}
	save(output_file_name, &winners);
	return 0;
}