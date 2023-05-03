/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:45 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:31:16 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	finish_step(t_dll *a)
{
	int			cliff;
	t_dllnode	*a_node;

	a_node = a->head.back;
	if (*(int *)a_node->contents > *(int *)a->tail.front->contents)
	{
		cliff = 1;
		a_node = a->head.back;
		while (*(int *)a_node->contents < *(int *)a_node->back->contents)
		{
			cliff++;
			a_node = a_node->back;
		}
		if (cliff * 2 < a->size)
		{
			while (cliff-- != 0)
				ra(a);
		}
		else
		{
			while (cliff++ != a->size)
				rra(a);
		}
	}
}

int	compare_func(t_dllnode *n1, t_dllnode *n2)
{
	if (*(int *)n1->contents > *(int *)n2->contents)
		return (1);
	else
		return (0);
}
