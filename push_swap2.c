/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:37 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:31:02 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_2or3(t_dll *a)
{
	if (a->size == 2)
		case2(a);
	else if (a->size == 3)
		case3(a);
}

void	case2(t_dll *a)
{
	int	num1;
	int	num2;

	num1 = *(int *)(a->head.back->contents);
	num2 = *(int *)(a->tail.front->contents);
	if (num1 > num2)
		sa(a);
}

void	case3(t_dll *a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = *(int *)(a->head.back->contents);
	num2 = *(int *)(a->head.back->back->contents);
	num3 = *(int *)(a->tail.front->contents);
	if (num1 > num2 && num3 > num1 && num3 > num2)
		sa(a);
	else if (num1 > num2 && num1 > num3 && num3 > num2)
		ra(a);
	else if (num2 > num1 && num2 > num3 && num1 > num3)
		rra(a);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		sa(a);
		rra(a);
	}
	else if (num2 > num1 && num2 > num3 && num3 > num1)
	{
		sa(a);
		ra(a);
	}
}
