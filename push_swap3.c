/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:01:14 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 20:01:15 by dmkael           ###   ########.fr       */
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
