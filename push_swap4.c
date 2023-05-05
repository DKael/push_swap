/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:41 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:38:42 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_r_info	calc_minimum_rotate1(int a_size, int b_size, int a_idx, int b_idx)
{
	t_r_info	info;

	if (a_idx * 2 < a_size && b_idx * 2 < b_size)
	{
		if (a_idx >= b_idx)
			info.calc_rotate = a_idx;
		else
			info.calc_rotate = b_idx;
		info.flag = 1;
	}
	else if (a_idx * 2 >= a_size && b_idx * 2 >= b_size)
	{
		if (a_size - a_idx >= b_size - b_idx)
			info.calc_rotate = a_size - a_idx;
		else
			info.calc_rotate = b_size - b_idx;
		info.flag = 2;
	}
	else
		return (calc_minimum_rotate2(a_size, b_size, a_idx, b_idx));
	return (info);
}

t_r_info	calc_minimum_rotate2(int a_size, int b_size, int a_idx, int b_idx)
{
	if (a_idx * 2 < a_size && b_idx * 2 >= b_size)
		return (calc_minimum_rotate3(a_size, b_size, a_idx, b_idx));
	else
		return (calc_minimum_rotate4(a_size, b_size, a_idx, b_idx));
}

t_r_info	calc_minimum_rotate3(int a_size, int b_size, int a_idx, int b_idx)
{
	t_r_info	info;
	int			temp_calc;

	info.calc_rotate = a_idx + b_size - b_idx;
	if (b_idx < a_size - a_idx)
	{
		temp_calc = b_idx;
		info.flag = 4;
	}
	else
	{
		temp_calc = a_size - a_idx;
		info.flag = 5;
	}
	if (temp_calc < info.calc_rotate)
		info.calc_rotate = temp_calc;
	else
		info.flag = 3;
	return (info);
}

t_r_info	calc_minimum_rotate4(int a_size, int b_size, int a_idx, int b_idx)
{
	t_r_info	info;
	int			temp_calc;

	info.calc_rotate = b_idx + a_size - a_idx;
	if (a_idx < b_size - b_idx)
	{
		temp_calc = a_idx;
		info.flag = 7;
	}
	else
	{
		temp_calc = b_size - b_idx;
		info.flag = 8;
	}
	if (temp_calc < info.calc_rotate)
		info.calc_rotate = temp_calc;
	else
		info.flag = 6;
	return (info);
}

void	set_location(t_rotate_count *r_count, t_r_info info)
{
	if (info.flag == 1 || info.flag == 4 || info.flag == 7)
	{
		r_count->a_rotate = info.a_check;
		r_count->b_rotate = info.b_check;
	}
	else if (info.flag == 2 || info.flag == 5 || info.flag == 8)
	{
		r_count->a_rotate = info.a_check - info.a_size;
		r_count->b_rotate = info.b_check - info.b_size;
	}
	else if (info.flag == 3)
	{
		r_count->a_rotate = info.a_check;
		r_count->b_rotate = info.b_check - info.b_size;
	}
	else if (info.flag == 6)
	{
		r_count->a_rotate = info.a_check - info.a_size;
		r_count->b_rotate = info.b_check;
	}
}
