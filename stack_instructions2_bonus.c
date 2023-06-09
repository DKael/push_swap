/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:16:08 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 18:14:59 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_dll *a)
{
	t_dllnode	*temp;

	if (a->size >= 2)
	{
		temp = a->head.back;
		a->head.back->back->front = &(a->head);
		a->head.back = a->head.back->back;
		a->size--;
		dll_add_tail(a, temp);
	}
}

void	rb(t_dll *b)
{
	t_dllnode	*temp;

	if (b->size >= 2)
	{
		temp = b->head.back;
		b->head.back->back->front = &(b->head);
		b->head.back = b->head.back->back;
		b->size--;
		dll_add_tail(b, temp);
	}
}

void	rr(t_dll *a, t_dll *b)
{
	t_dllnode	*temp;

	if (a->size >= 2)
	{
		temp = a->head.back;
		a->head.back->back->front = &(a->head);
		a->head.back = a->head.back->back;
		a->size--;
		dll_add_tail(a, temp);
	}
	if (b->size >= 2)
	{
		temp = b->head.back;
		b->head.back->back->front = &(b->head);
		b->head.back = b->head.back->back;
		b->size--;
		dll_add_tail(b, temp);
	}
}
