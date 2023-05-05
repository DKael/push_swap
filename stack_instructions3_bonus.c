/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:16:11 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:23:21 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_dll *a)
{
	t_dllnode	*temp;

	if (a->size >= 2)
	{
		temp = a->tail.front;
		a->tail.front->front->back = &(a->tail);
		a->tail.front = a->tail.front->front;
		a->size--;
		dll_add_head(a, temp);
	}
}

void	rrb(t_dll *b)
{
	t_dllnode	*temp;

	if (b->size >= 2)
	{
		temp = b->tail.front;
		b->tail.front->front->back = &(b->tail);
		b->tail.front = b->tail.front->front;
		b->size--;
		dll_add_head(b, temp);
	}
}

void	rrr(t_dll *a, t_dll *b)
{
	t_dllnode	*temp;

	if (a->size >= 2)
	{
		temp = a->tail.front;
		a->tail.front->front->back = &(a->tail);
		a->tail.front = a->tail.front->front;
		a->size--;
		dll_add_head(a, temp);
	}
	if (b->size >= 2)
	{
		temp = b->tail.front;
		b->tail.front->front->back = &(b->tail);
		b->tail.front = b->tail.front->front;
		b->size--;
		dll_add_head(b, temp);
	}
}
