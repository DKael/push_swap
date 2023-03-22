/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:49:36 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 21:49:37 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static t_list	*m(t_list *l, t_list *n, void *(*f)(void *), void (*d)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*f_content;

	f_content = f(lst->content);
	new_lst = ft_lstnew(f_content);
	if (new_lst == NULL)
	{
		del(f_content);
		return (NULL);
	}
	lst = lst->next;
	return (m(lst, new_lst, f, del));
}

static t_list	*m(t_list *l, t_list *n, void *(*f)(void *), void (*d)(void *))
{
	void	*f_content;
	t_list	*new_iter;

	new_iter = n;
	while (l != NULL)
	{
		f_content = f(l->content);
		new_iter->next = ft_lstnew(f_content);
		if (new_iter->next == NULL)
		{
			d(f_content);
			ft_lstclear(&n, d);
			return (NULL);
		}
		new_iter = new_iter->next;
		l = l->next;
	}
	return (n);
}
