/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:16 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:17 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*b_char;

	index = 0;
	b_char = (unsigned char *)s;
	while (index < n)
	{
		b_char[index] = '\0';
		index++;
	}
}
