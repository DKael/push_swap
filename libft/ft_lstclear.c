/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:56:52 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 20:56:53 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*delete;
	t_list	*next_node;

	if ((*lst) != NULL)
	{
		next_node = (*lst);
		while (next_node != NULL)
		{
			delete = next_node;
			next_node = next_node->next;
			del(delete->content);
			free(delete);
		}
		free(next_node);
		*lst = NULL;
	}
}
