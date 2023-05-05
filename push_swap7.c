/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:48 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:38:47 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_minimum_rotate1(t_dll *a, t_dll *b,
			t_rotate_count *r_count, int pivot)
{
	int			a_check;
	int			b_check;
	t_dllnode	*b_node;
	int			min_rotate;
	t_r_info	pos_info;

	b_check = -1;
	b_node = b->head.back;
	min_rotate = INT_MAX;
	while (++b_check < b->size)
	{
		if (*(int *)b_node->contents > pivot)
		{
			a_check = find_a_check1(a, *(int *)b_node->contents);
			pos_info = calc_minimum_rotate1(a->size, b->size, a_check, b_check);
			if (pos_info.calc_rotate < min_rotate)
			{
				find_minimum_rotate3(a_check, b_check, a->size, &pos_info);
				pos_info.b_size = b->size;
				set_location(r_count, pos_info);
				min_rotate = pos_info.calc_rotate;
			}
		}
		b_node = b_node->back;
	}
}

void	find_minimum_rotate2(t_dll *a, t_dll *b, t_rotate_count *r_count)
{
	int			a_check;
	int			b_check;
	t_dllnode	*b_node;
	int			min_rotate;
	t_r_info	pos_info;

	b_check = -1;
	b_node = b->head.back;
	min_rotate = INT_MAX;
	while (++b_check < b->size)
	{
		a_check = find_a_check1(a, *(int *)b_node->contents);
		pos_info = calc_minimum_rotate1(a->size, b->size, a_check, b_check);
		if (pos_info.calc_rotate < min_rotate)
		{
			pos_info.a_check = a_check;
			pos_info.b_check = b_check;
			pos_info.a_size = a->size;
			pos_info.b_size = b->size;
			set_location(r_count, pos_info);
			min_rotate = pos_info.calc_rotate;
		}
		b_node = b_node->back;
	}
}

void	find_minimum_rotate3(int a_check, int b_check,
			int a_size, t_r_info *pos_info)
{
	pos_info->a_check = a_check;
	pos_info->b_check = b_check;
	pos_info->a_size = a_size;
}
