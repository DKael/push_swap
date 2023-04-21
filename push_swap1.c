/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:01:05 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 20:01:06 by dmkael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// #include <stdio.h>
// void print_stack(t_dll *a, t_dll *b)
// {
// 	t_dllnode *dtemp;
// 	fprintf(stderr, "\na stack : ");
// 	dtemp = a->head.back;
// 	while (dtemp != &(a->tail))
// 	{
// 		fprintf(stderr, "%d ", *(int *)dtemp->contents);
// 		dtemp = dtemp->back;
// 	}
// 	fprintf(stderr, "\nb stack : ");
// 	dtemp = b->head.back;
// 	while (dtemp != &(b->tail))
// 	{
// 		fprintf(stderr, "%d ", *(int *)dtemp->contents);
// 		dtemp = dtemp->back;
// 	}
// }

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
	int	a_rotate;
	int	b_rotate;

	split_by_pivot(input_count, sorted_input, a, b);
	sort_2or3(a);
	while (b->size != 0)
	{
		a_rotate = 0;
		b_rotate = 0;
		find_minimum_rotate(a, b, &a_rotate, &b_rotate);
		do_rotate1(a_rotate, b_rotate, a, b);
		pa(a, b);
	}
	finish_step(a);
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
		if (dtemp == NULL)
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

void	split_by_pivot(int input_count, int *sorted_input, t_dll *a, t_dll *b)
{
	int	temp;
	int	idx;
	int	pivot1;
	int	pivot2;

	idx = 0;
	pivot1 = sorted_input[input_count / 3 - 1];
	pivot2 = sorted_input[input_count * 2 / 3 - 1];
	while (++idx <= input_count)
	{
		temp = *((int *)a->head.back->contents);
		if (temp > pivot2)
			ra(a);
		else if (pivot1 < temp && temp <= pivot2)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
	}
	while (a->size > 3)
		pb(a, b);
}
