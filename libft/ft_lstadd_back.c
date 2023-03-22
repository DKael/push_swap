/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:08:17 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 20:08:18 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node_ptr;

	if ((*lst) == NULL)
	{
		(*lst) = new;
	}
	else
	{
		node_ptr = *lst;
		while (node_ptr->next != NULL)
			node_ptr = node_ptr->next;
		node_ptr->next = new;
	}
}
