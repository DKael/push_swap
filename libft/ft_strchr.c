/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:27:55 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:27:55 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	if ((char)c == '\0')
		return ((char *)s + index);
	return ((void *)0);
}
