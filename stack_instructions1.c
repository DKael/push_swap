/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:59:06 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 19:59:07 by dmkael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_dll *a)
{
	write(1, "sa\n", 3);
	if (a->size >= 2)
		dll_swap_node(a->head.back, a->head.back->back);
}

void	sb(t_dll *b)
{
	write(1, "sb\n", 3);
	if (b->size >= 2)
		dll_swap_node(b->head.back, b->head.back->back);
}

void	ss(t_dll *a, t_dll *b)
{
	write(1, "ss\n", 3);
	if (a->size >= 2)
		dll_swap_node(a->head.back, a->head.back->back);
	if (b->size >= 2)
		dll_swap_node(b->head.back, b->head.back->back);
}

void	pa(t_dll *a, t_dll *b)
{
	t_dllnode	*temp;

	write(1, "pa\n", 3);
	if (b->size >= 2)
	{
		temp = b->head.back;
		b->head.back->back->front = &(b->head);
		b->head.back = b->head.back->back;
		dll_add_head(a, temp);
		b->size--;
	}
	else if (b->size == 1)
	{
		temp = b->head.back;
		dll_add_head(a, temp);
		dll_init(b);
	}
}

void	pb(t_dll *a, t_dll *b)
{
	t_dllnode	*temp;

	write(1, "pb\n", 3);
	if (a->size >= 2)
	{
		temp = a->head.back;
		a->head.back->back->front = &(a->head);
		a->head.back = a->head.back->back;
		dll_add_head(b, temp);
		a->size--;
	}
	else if (a->size == 1)
	{
		temp = a->head.back;
		dll_add_head(b, temp);
		dll_init(a);
	}
}
