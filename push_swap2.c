/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:01:08 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 20:01:10 by dmkael           ###   ########.fr       */
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

void	find_minimum_rotate(t_dll *a, t_dll *b, int *a_rotate, int *b_rotate)
{
	int			a_check;
	int			b_check;
	t_dllnode	*b_node;
	int			min_rotate;
	t_r_info	cur_pos_info;

	b_check = 0;
	b_node = b->head.back;
	min_rotate = INT_MAX;
	while (b_check < b->size)
	{
		a_check = find_a_check1(a, *(int *)b_node->contents);
		cur_pos_info = calc_minimum_rotate1(a->size, b->size, a_check, b_check);
		if (cur_pos_info.calc_rotate < min_rotate)
		{
			cur_pos_info.a_check = a_check;
			cur_pos_info.b_check = b_check;
			cur_pos_info.a_size = a->size;
			cur_pos_info.b_size = b->size;
			set_location(a_rotate, b_rotate, cur_pos_info);
			min_rotate = cur_pos_info.calc_rotate;
		}
		b_node = b_node->back;
		b_check++;
	}
}
