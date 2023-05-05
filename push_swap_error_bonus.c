/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:51 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:22:45 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	array_free(int argc, char ***argv_split)
{
	int	argv_idx;
	int	split_idx;

	argv_idx = -1;
	while (++argv_idx < argc - 1)
	{
		split_idx = -1;
		while (argv_split[argv_idx][++split_idx] != NULL)
			free(argv_split[argv_idx][split_idx]);
		free(argv_split[argv_idx]);
	}
	free(argv_split);
}

void	error_print(int argc, char ***argv_split, int flag)
{
	if (flag == 1)
		write(2, "Error\n", 6);
	array_free(argc, argv_split);
	exit(1);
}

void	remove_contents(void *content)
{
	free(content);
}
