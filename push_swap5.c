/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:01:21 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 20:01:22 by dmkael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_rotate1(int a_rotate, int b_rotate, t_dll *a, t_dll *b)
{
	if (a_rotate >= 0 && b_rotate >= 0)
		do_rotate2(a_rotate, b_rotate, a, b);
	else if (a_rotate <= 0 && b_rotate <= 0)
		do_rotate3(a_rotate, b_rotate, a, b);
	else if (a_rotate >= 0 && b_rotate <= 0)
		do_rotate4(a_rotate, b_rotate, a, b);
	else
		do_rotate5(a_rotate, b_rotate, a, b);
}

void	do_rotate2(int a_rotate, int b_rotate, t_dll *a, t_dll *b)
{
	int	idx1;

	idx1 = -1;
	if (a_rotate >= b_rotate)
	{
		while (++idx1 < b_rotate)
			rr(a, b);
		while (idx1++ < a_rotate)
			ra(a);
	}
	else
	{
		while (++idx1 < a_rotate)
			rr(a, b);
		while (idx1++ < b_rotate)
			rb(b);
	}
}

void	do_rotate3(int a_rotate, int b_rotate, t_dll *a, t_dll *b)
{
	int	idx1;

	idx1 = -1;
	a_rotate *= -1;
	b_rotate *= -1;
	if (a_rotate >= b_rotate)
	{
		while (++idx1 < b_rotate)
			rrr(a, b);
		while (idx1++ < a_rotate)
			rra(a);
	}
	else
	{
		while (++idx1 < a_rotate)
			rrr(a, b);
		while (idx1++ < b_rotate)
			rrb(b);
	}
}

void	do_rotate4(int a_rotate, int b_rotate, t_dll *a, t_dll *b)
{
	int	idx1;

	idx1 = 0;
	b_rotate *= -1;
	while (idx1 < a_rotate)
	{
		ra(a);
		idx1++;
	}
	idx1 = 0;
	while (idx1 < b_rotate)
	{
		rrb(b);
		idx1++;
	}
}

void	do_rotate5(int a_rotate, int b_rotate, t_dll *a, t_dll *b)
{
	int	idx1;

	idx1 = 0;
	a_rotate *= -1;
	while (idx1 < a_rotate)
	{
		rra(a);
		idx1++;
	}
	idx1 = 0;
	while (idx1 < b_rotate)
	{
		rb(b);
		idx1++;
	}
}
