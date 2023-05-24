/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:34 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:37:41 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push_swap1(int input_count, int *sorted_input)
{
	t_dll	a;
	t_dll	b;

	dll_init(&a);
	dll_init(&b);
	make_stack(&a, input_count, sorted_input);
	sorting(sorted_input, input_count);
	check_duplications(&a, input_count, sorted_input);
	if (a.size <= 3)
		sort_2or3(&a);
	else
		do_push_swap2(input_count, sorted_input, &a, &b);
	dll_clear(&a, remove_contents);
	dll_clear(&b, remove_contents);
}

void	do_push_swap2(int input_count, int *sorted_input, t_dll *a, t_dll *b)
{
	t_pivot			pivots;
	t_rotate_count	r_count;

	pivots = split_by_pivot(input_count, sorted_input, a, b);
	sort_2or3(a);
	do_push_swap3(a, b, &pivots, &r_count);
	while (b->size != 0)
	{
		r_count.a_rotate = 0;
		r_count.b_rotate = 0;
		find_minimum_rotate2(a, b, &r_count);
		do_rotate1(r_count.a_rotate, r_count.b_rotate, a, b);
		pa(a, b);
	}
	finish_step(a);
}

void	do_push_swap3(t_dll *a, t_dll *b,
			t_pivot *pivots, t_rotate_count *r_count)
{
	while ((pivots->above_pivot2)-- > 0)
	{
		r_count->a_rotate = 0;
		r_count->b_rotate = 0;
		find_minimum_rotate1(a, b, r_count, pivots->pivot2);
		do_rotate1(r_count->a_rotate, r_count->b_rotate, a, b);
		pa(a, b);
	}
	while ((pivots->above_pivot1)-- > 0)
	{
		r_count->a_rotate = 0;
		r_count->b_rotate = 0;
		find_minimum_rotate1(a, b, r_count, pivots->pivot1);
		do_rotate1(r_count->a_rotate, r_count->b_rotate, a, b);
		pa(a, b);
	}
}

void	make_stack(t_dll *a, int input_count, int *sorted_input)
{
	t_dllnode	*dtemp;
	int			*ctemp;
	int			idx;

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

void	check_duplications(t_dll *a, int input_count, int *sorted_input)
{
	int	idx;

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
