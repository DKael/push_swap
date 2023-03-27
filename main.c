// #include "double_linked_list.h"
// #include "get_next_line/get_next_line.h"
// #include "libft/libft.h"
#include "libft/ft_split.c"
#include "libft/ft_strdup.c"
#include "libft/ft_strlen.c"
#include "libft/ft_atoi_int.c"
#include <unistd.h>
#include <stdlib.h>

void array_free(int argc, char ***argv_split);

#include <stdio.h>

int main(int argc, char **argv)
{
	int argv_idx;
	int split_idx;
	int idx;
	int input_count;
	char ***argv_split;
	int *sorted_input;
	int sorted_idx;
	char temp;

	if (argc != 1)
	{
		// argument split
		argv_split = (char ***)malloc(sizeof(char **) * (argc - 1));
		if (argv_split == NULL)
			exit(1);
		argv_idx = 0;
		while (++argv_idx < argc)
		{
			argv_split[argv_idx - 1] = ft_split(argv[argv_idx], ' ');
			if (argv_split[argv_idx - 1] == NULL)
			{
				while (--argv_idx != 0)
					free(argv_split[argv_idx - 1]);
				free(argv_split);
				exit(1);
			}
		}
		// check non numeric character
		argv_idx = -1;
		while (++argv_idx < argc - 1)
		{
			split_idx = -1;
			while (argv_split[argv_idx][++split_idx] != NULL)
			{
				idx = 0;
				temp = argv_split[argv_idx][split_idx][idx];
				if (temp == '-' || temp == '+')
				{
					temp = argv_split[argv_idx][split_idx][idx + 1];
					if (temp == '\0')
					{
						write(1, "Error", 5);
						array_free(argc, argv_split);
						exit(1);
					}
				}
				while (argv_split[argv_idx][split_idx][++idx] != '\0')
				{

					if ('0' > temp || temp > '9')
					{
						write(1, "Error", 5);
						array_free(argc, argv_split);
						exit(1);
					}
				}
			}
		}
		// count total numeric input
		argv_idx = -1;
		input_count = 0;
		while (++argv_idx < argc - 1)
		{
			split_idx = -1;
			while (argv_split[argv_idx][++split_idx] != NULL)
				input_count++;
		}
		// make array use to sorting input
		sorted_input = (int *)malloc(sizeof(int) * input_count);
		if (sorted_input == NULL)
		{
			array_free(argc, argv_split);
			exit(1);
		}
		argv_idx = -1;
		sorted_idx = -1;
		while (++argv_idx < argc - 1)
		{
			split_idx = -1;
			while (argv_split[argv_idx][++split_idx] != NULL)
			{
				sorted_input[++sorted_idx] = ft_atoi_int(argv_split[argv_idx][split_idx]);
				if ((sorted_input[sorted_idx] == 0 && argv_split[argv_idx][split_idx][0] != '0') 
					|| (sorted_input[sorted_idx] == -1 && argv_split[argv_idx][split_idx][0] != '-' 
					&& argv_split[argv_idx][split_idx][1] != '1'))
				{
					write(1, "Error", 5);
					free(sorted_input);
					array_free(argc, argv_split);
					exit(1);
				}
			}
		}
		for (int i = 0; i < input_count; i++)
		{
			printf("%d ", sorted_input[i]);
		}
		// array sorting

		// list free part
		free(sorted_input);
		array_free(argc, argv_split);
	}
}

void array_free(int argc, char ***argv_split)
{
	int argv_idx;
	int split_idx;

	argv_idx = -1;
	while (++argv_idx < argc - 1)
	{
		split_idx = -1;
		while (argv_split[argv_idx][++split_idx] != NULL)
			free(argv_split[argv_idx][split_idx]);
		free(argv_split[argv_idx]);
	}
	free(argv_split);
}