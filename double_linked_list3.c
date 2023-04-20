/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:44:10 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 19:44:13 by dmkael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

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
