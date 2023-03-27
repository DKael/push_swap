/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:23 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:24 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

int ft_atoi_int(const char *str)
{
	int idx;
	int sign;
	int nb;

	idx = 0;
	sign = 1;
	nb = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
		if (str[idx++] == '-')
			sign = -1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		if (nb > INT_MAX / 10 || (nb == (INT_MAX / 10) && str[idx] - '0' > (INT_MAX % 10) - ((sign - 1) / 2)))
			return (0);
		nb = nb * 10 + (str[idx++] - '0');
	}
	return ((int)nb * sign);
}
