/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:25 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:26 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	if (dst != NULL || src != NULL)
	{
		index = 0;
		dst_char = (unsigned char *)dst;
		src_char = (unsigned char *)src;
		while (index < n)
		{
			dst_char[index] = src_char[index];
			index++;
		}
	}
	return (dst);
}
