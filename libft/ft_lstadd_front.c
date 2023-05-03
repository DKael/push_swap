/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:27:39 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:27:39 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
	{
		(*lst) = new;
	}
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}
