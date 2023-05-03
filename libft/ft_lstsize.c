/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:27:45 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:27:45 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*node_ptr;

	if (lst == NULL)
	{
		return (0);
	}
	length = 1;
	node_ptr = lst;
	while (node_ptr->next != NULL)
	{
		length++;
		node_ptr = node_ptr->next;
	}
	return (length);
}
