/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:31:51 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:31:52 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_ucptr;

	index = -1;
	s_ucptr = (unsigned char *)s;
	while (++index < n)
	{
		if (s_ucptr[index] == (unsigned char)c)
			return ((void *)((size_t)s_ucptr + index));
	}
	return (NULL);
}
