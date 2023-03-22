// #include "double_linked_list.h"
// #include "get_next_line/get_next_line.h"
// #include "libft/libft.h"
#include "libft/ft_split.c"
#include "libft/ft_strdup.c"
#include "libft/ft_strlen.c"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char** argv)
{
	int		argv_index;
	int		split_index;
	int		input_count;
	char	***argv_split_result;
	int		*sorted_input;

	if (argc != 1)
	{
		argv_index = 0;
		argv_split_result = (char***)malloc(sizeof(char**) * (argc - 1));
		while (++argv_index < argc)
			argv_split_result[argv_index - 1] = ft_split(argv[argv_index], ' ');
		argv_index = -1;
		input_count = 0;
		while (++argv_index < argc - 1)
		{
			split_index = -1;
			while (argv_split_result[argv_index][++split_index] != '\0')
				input_count++;
		}

		printf("input count : %d\n", input_count);
	}
}