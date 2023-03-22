/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:25:14 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 17:25:15 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	write(fd, s, sizeof(char) * index);
	write(fd, "\n", sizeof(char));
}
