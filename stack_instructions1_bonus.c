/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions1_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:59 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 18:14:49 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_dll *a)
{
	if (a->size >= 2)
		dll_swap_node(a->head.back, a->head.back->back);
}

void	sb(t_dll *b)
{
	if (b->size >= 2)
		dll_swap_node(b->head.back, b->head.back->back);
}

void	ss(t_dll *a, t_dll *b)
{
	if (a->size >= 2)
		dll_swap_node(a->head.back, a->head.back->back);
	if (b->size >= 2)
		dll_swap_node(b->head.back, b->head.back->back);
}

void	pa(t_dll *a, t_dll *b)
{
	t_dllnode	*temp;

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
