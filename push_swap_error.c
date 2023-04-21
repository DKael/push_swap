/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:52:44 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 19:52:46 by dmkael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
