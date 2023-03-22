/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:43 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:44 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	index;
	size_t	index1;

	index = 0;
	index1 = -1;
	while (src[index] != '\0')
		index++;
	if (index >= dsize)
	{
		while (++index1 + 1 < dsize)
			dst[index1] = src[index1];
	}
	else
	{
		while (src[++index1] != '\0')
			dst[index1] = src[index1];
	}
	if (dsize != 0)
		dst[index1] = '\0';
	return (index);
}
