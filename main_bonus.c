/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:32 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/05 00:11:37 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void make_instr_list(t_dll *instruction)
{
	char instr_buffer[5];
	char *instr;
	int read_count;
	t_dllnode *node;

	dll_init(instruction);
	read_count = read(0, instr_buffer, 5);
	while (read_count != 0)
	{
		if (read_count == -1)
			exit(1);
		instr = ft_strndup(instr_buffer, read_count);
		if (instr == NULL)
			exit(1);
		node = dll_new_node(instr);
		if (node == NULL)
			exit(1);
		dll_add_tail(instruction, node);
		read_count = read(0, instr_buffer, 5);
	}
}

void make_stack(t_dll *a, int input_count, int *sorted_input)
{
	t_dllnode *dtemp;
	int *ctemp;
	int idx;

	idx = -1;
	while (++idx < input_count)
	{
		ctemp = (int *)malloc(sizeof(int) * 1);
		if (ctemp == NULL)
		{
			dll_clear(a, remove_contents);
			free(sorted_input);
			exit(1);
		}
		*ctemp = sorted_input[idx];
		dtemp = dll_new_node(ctemp);
		if (dtemp == NULL)
		{
			dll_clear(a, remove_contents);
			free(sorted_input);
			exit(1);
		}
		dll_add_tail(a, dtemp);
	}
}

void check_duplications(t_dll *a, int input_count, int *sorted_input)
{
	int idx;

	idx = -1;
	while (++idx < input_count - 1)
	{
		if (sorted_input[idx] == sorted_input[idx + 1])
		{
			dll_clear(a, remove_contents);
			free(sorted_input);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

void do_push_swap1(int input_count, int *sorted_input)
{
	t_dll a;
	t_dll b;
	t_dll instruction;
	t_dllnode *node;

	dll_init(&a);
	dll_init(&b);
	make_stack(&a, input_count, sorted_input);
	sorting(sorted_input, input_count);
	check_duplications(&a, input_count, sorted_input);
	make_instr_list(&instruction);

	node = instruction.head.back;
	while (node != &(instruction.tail))
	{
		if (ft_strcmp((char *)node->contents, "sa\n") == 0)
			sa(&a);
		else if (ft_strcmp((char *)node->contents, "sb\n") == 0)
			sb(&b);
		else if (ft_strcmp((char *)node->contents, "ss\n") == 0)
			ss(&a, &b);
		else if (ft_strcmp((char *)node->contents, "pa\n") == 0)
			pa(&a, &b);
		else if (ft_strcmp((char *)node->contents, "pb\n") == 0)
			pb(&a, &b);
		else if (ft_strcmp((char *)node->contents, "ra\n") == 0)
			ra(&a);
		else if (ft_strcmp((char *)node->contents, "rb\n") == 0)
			rb(&b);
		else if (ft_strcmp((char *)node->contents, "rr\n") == 0)
			rr(&a, &b);
		else if (ft_strcmp((char *)node->contents, "rra\n") == 0)
			rra(&a);
		else if (ft_strcmp((char *)node->contents, "rrb\n") == 0)
			rrb(&b);
		else if (ft_strcmp((char *)node->contents, "rrr\n") == 0)
			rrr(&a, &b);
		else
		{
			dll_clear(&a, remove_contents);
			dll_clear(&b, remove_contents);
			dll_clear(&instruction, remove_contents);
			free(sorted_input);
			write(2, "Error\n", 6);
			exit(1);
		}
		node = node->back;
	}
	if (b.size != 0)
	{
		dll_clear(&a, remove_contents);
		dll_clear(&b, remove_contents);
		dll_clear(&instruction, remove_contents);
		free(sorted_input);
		write(1, "KO\n", 3);
		exit(1);
	}
	node = a.head.back;
	while (node != a.tail.front)
	{
		if (*(int *)node->contents > *(int *)node->back->contents)
		{
			dll_clear(&a, remove_contents);
			dll_clear(&b, remove_contents);
			dll_clear(&instruction, remove_contents);
			free(sorted_input);
			write(1, "KO\n", 3);
			exit(1);
		}
		node = node->back;
	}
	dll_clear(&a, remove_contents);
	dll_clear(&b, remove_contents);
	dll_clear(&instruction, remove_contents);
	write(1, "OK\n", 3);
}

int main(int argc, char **argv)
{
	int input_count;
	char ***argv_split;
	int *sorted_input;

	if (argc != 1)
	{
		argv_split = argument_split(argc, argv);
		
		check_non_numeric_character(argc, argv_split);
		input_count = count_total_numeric_input(argc, argv_split);
		sorted_input = make_array_use_to_check(input_count, argc, argv_split);
		array_free(argc, argv_split);

		do_push_swap1(input_count, sorted_input);
		free(sorted_input);
	}
}
