/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:14:42 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/08 14:17:51 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	make_instr_list(t_dll *instruction)
{
	char		*instr;
	t_dllnode	*node;

	dll_init(instruction);
	instr = get_next_line(0);
	while (instr != NULL)
	{
		node = dll_new_node(instr);
		if (node == NULL)
			exit(1);
		dll_add_tail(instruction, node);
		instr = get_next_line(0);
	}
}

void	make_stack(t_dll *a, int input_count, int *sorted_input)
{
	t_dllnode	*dtemp;
	int			*ctemp;
	int			idx;

	idx = -1;
	while (++idx < input_count)
	{
		ctemp = (int *)malloc(sizeof(int) * 1);
		if (ctemp == NULL)
		{
			dll_clear(a, remove_contents);
			free(sorted_input);
			exit(1);
		}
		*ctemp = sorted_input[idx];
		dtemp = dll_new_node(ctemp);
		if (dtemp == NULL)
		{
			dll_clear(a, remove_contents);
			free(sorted_input);
			exit(1);
		}
		dll_add_tail(a, dtemp);
	}
}

void	check_duplications(t_dll *a, int input_count, int *sorted_input)
{
	int	idx;

	idx = -1;
	while (++idx < input_count - 1)
	{
		if (sorted_input[idx] == sorted_input[idx + 1])
		{
			dll_clear(a, remove_contents);
			free(sorted_input);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}
