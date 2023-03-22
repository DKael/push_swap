/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:45:42 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 19:45:43 by hyungdki         ###   ########.fr       */
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
