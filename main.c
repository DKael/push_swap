#include "push_swap.h"

#include "error.c"
#include "parsing.c"
#include "push_swap1.c"
#include "push_swap2.c"
#include "push_swap3.c"
#include "push_swap4.c"
#include "push_swap5.c"
#include "push_swap6.c"
#include "quick_sort.c"
#include "stack_instructions1.c"
#include "stack_instructions2.c"
#include "stack_instructions3.c"

#include "libft/ft_split.c"
#include "libft/ft_strdup.c"
#include "libft/ft_strlen.c"
#include "double_linked_list1.c"
#include "double_linked_list2.c"
#include "double_linked_list3.c"

int main(int argc, char **argv)
{
	int		input_count;
	char	***argv_split;
	int		*sorted_input;

	if (argc != 1)
	{
		argv_split = argument_split(argc, argv);
		check_non_numeric_character(argc, argv_split);
		input_count = count_total_numeric_input(argc, argv_split);
		sorted_input = make_array_use_to_check(input_count, argc, argv_split);
		if (is_sorted(input_count, sorted_input) == 1)
			return (0);		
		array_free(argc, argv_split);
		do_push_swap(input_count, sorted_input);
		free(sorted_input);
	}
}
