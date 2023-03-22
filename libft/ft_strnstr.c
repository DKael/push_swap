/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:12 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:13 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	ni;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack == NULL && len == 0)
		return (NULL);
	hi = 0;
	while (haystack[hi] != '\0' && hi < len)
	{
		if (haystack[hi] == needle[0])
		{
			ni = 0;
			while (needle[++ni] != '\0')
				if (haystack[hi + ni] != needle[ni] || !(hi + ni < len))
					break ;
			if (needle[ni] == '\0')
				return ((char *)&haystack[hi]);
		}
		hi++;
	}
	return (NULL);
}
