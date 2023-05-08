/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:16:03 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/08 14:56:21 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_push_swap1(int input_count, int *sorted_input)
{
	t_dll_col	dll_col;

	dll_init(&dll_col.a);
	dll_init(&dll_col.b);
	make_stack(&dll_col.a, input_count, sorted_input);
	sorting(sorted_input, input_count);
	check_duplications(&dll_col.a, input_count, sorted_input);
	make_instr_list(&dll_col.instruction);
	do_push_swap2(&dll_col, sorted_input);
}

void	do_push_swap2(t_dll_col *dll_col, int *sorted_input)
{
	t_dllnode	*node;

	node = dll_col->instruction.head.back;
	while (node != &(dll_col->instruction.tail))
	{
		if (exe_instr(dll_col, (char *)node->contents) == 1)
			finish_step(dll_col, sorted_input, 1);
		node = node->back;
	}
	if (dll_col->b.size != 0)
		finish_step(dll_col, sorted_input, 2);
	node = dll_col->a.head.back;
	while (node != dll_col->a.tail.front)
	{
		if (*(int *)node->contents > *(int *)node->back->contents)
			finish_step(dll_col, sorted_input, 2);
		node = node->back;
	}
	finish_step(dll_col, sorted_input, 3);
}

int	exe_instr(t_dll_col *dll_col, char *contents)
{
	if (ft_strncmp(contents, "sa", 2) == 0)
		sa(&dll_col->a);
	else if (ft_strncmp(contents, "sb", 2) == 0)
		sb(&dll_col->b);
	else if (ft_strncmp(contents, "ss", 2) == 0)
		ss(&dll_col->a, &dll_col->b);
	else if (ft_strncmp(contents, "pa", 2) == 0)
		pa(&dll_col->a, &dll_col->b);
	else if (ft_strncmp(contents, "pb", 2) == 0)
		pb(&dll_col->a, &dll_col->b);
	else if (ft_strncmp(contents, "rra", 3) == 0)
		rra(&dll_col->a);
	else if (ft_strncmp(contents, "rrb", 3) == 0)
		rrb(&dll_col->b);
	else if (ft_strncmp(contents, "rrr", 3) == 0)
		rrr(&dll_col->a, &dll_col->b);
	else if (ft_strncmp(contents, "ra", 2) == 0)
		ra(&dll_col->a);
	else if (ft_strncmp(contents, "rb", 2) == 0)
		rb(&dll_col->b);
	else if (ft_strncmp(contents, "rr", 2) == 0)
		rr(&dll_col->a, &dll_col->b);
	else
		return (1);
	return (0);
}

void	finish_step(t_dll_col *dll_col, int *sorted_input, int flag)
{
	dll_clear(&dll_col->a, remove_contents);
	dll_clear(&dll_col->b, remove_contents);
	dll_clear(&dll_col->instruction, remove_contents);
	free(sorted_input);
	if (flag == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (flag == 2)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	else
	{
		write(1, "OK\n", 3);
		exit(0);
	}	
}
