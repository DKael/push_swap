/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:28 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:07:43 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list_bonus.h"

void	dll_del_node(t_dll *dll, t_dllnode *node, void (*del)(void *))
{
	if (dll_is_in(dll, node) == true)
	{
		if (dll->size == 1)
			dll_init(dll);
		else if (node->front == &(dll->head))
		{
			dll->head.back = node->back;
			node->back->front = &(dll->head);
		}
		else if (node->front == &(dll->head))
		{
			dll->tail.front = node->front;
			node->front->back = &(dll->tail);
		}
		else
		{
			node->front->back = node->back;
			node->back->front = node->front;
		}
		del(node->contents);
		free(node);
		dll->size--;
	}
}

int	dll_node_compare(t_dllnode *n1, t_dllnode *n2,
	int (*compare)(t_dllnode *, t_dllnode *))
{
	int	result;

	result = compare(n1, n2);
	if (result == 1)
		return (1);
	else if (result == -1)
		return (-1);
	else
		return (0);
}
