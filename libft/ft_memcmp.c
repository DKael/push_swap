/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:01 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:03 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_cptr;
	unsigned char	*s2_cptr;

	index = -1;
	s1_cptr = (unsigned char *)s1;
	s2_cptr = (unsigned char *)s2;
	while (++index < n)
	{
		if (s1_cptr[index] != s2_cptr[index])
			return ((int)(s1_cptr[index] - s2_cptr[index]));
	}
	return (0);
}
