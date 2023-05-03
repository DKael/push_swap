/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:39 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:31:06 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_a_check1(t_dll *a, int num)
{
	t_dllnode	*a_node;

	a_node = a->head.back;
	if (*(int *)a_node->contents < *(int *)a->tail.front->contents)
		return (find_a_check2(a, num, a_node));
	else
		return (find_a_check3(a, num, a_node));
}

int	find_a_check2(t_dll *a, int num, t_dllnode *a_node)
{
	int	a_temp;

	a_temp = 0;
	if (num < *(int *)a_node->contents || num > *(int *)a->tail.front->contents)
		return (0);
	else
	{
		while (a_temp + 1 < a->size)
		{
			if (*(int *)a_node->contents < num
				&& num < *(int *)a_node->back->contents)
				return (a_temp + 1);
			a_temp++;
			a_node = a_node->back;
		}
		return (0);
	}
}

int	find_a_check3(t_dll *a, int num, t_dllnode *a_node)
{
	int	a_temp;

	if (*(int *)a_node->contents < num)
	{
		a_temp = 0;
		while (*(int *)a_node->contents < *(int *)a_node->back->contents)
		{
			if (*(int *)a_node->contents < num
				&& num < *(int *)a_node->back->contents)
				return (a_temp + 1);
			a_temp++;
			a_node = a_node->back;
		}
		return (a_temp + 1);
	}
	else if (num < *(int *)a->tail.front->contents)
		return (find_a_check4(a, num, a_node));
	else
		return (0);
}

int	find_a_check4(t_dll *a, int num, t_dllnode *a_node)
{
	int	a_temp;

	a_temp = a->size - 1;
	a_node = a->tail.front;
	while (*(int *)a_node->contents > *(int *)a_node->front->contents)
	{
		if (*(int *)a_node->contents > num
			&& num > *(int *)a_node->front->contents)
			return (a_temp);
		a_temp--;
		a_node = a_node->front;
	}
	return (a_temp);
}

t_pivot	split_by_pivot(int input_cnt, int *sorted_input, t_dll *a, t_dll *b)
{
	int		temp;
	int		idx;
	t_pivot	pivot;

	idx = 0;
	pivot.pivot2 = sorted_input[input_cnt * 2 / 3 - 1];
	pivot.pivot1 = sorted_input[input_cnt / 3 - 1];
	pivot.above_pivot2 = input_cnt - (input_cnt * 2 / 3) - 3;
	pivot.above_pivot1 = input_cnt - (pivot.above_pivot2 + 3) - (input_cnt / 3);
	while (++idx <= input_cnt)
	{
		temp = *((int *)a->head.back->contents);
		if (temp > pivot.pivot2)
			ra(a);
		else if (pivot.pivot1 < temp && temp <= pivot.pivot2)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
	}
	while (a->size > 3)
		pb(a, b);
	return (pivot);
}
