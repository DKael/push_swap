/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:54 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 23:38:50 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	***argument_split(int argc, char **argv)
{
	char	***argv_split;
	int		argv_idx;

	argv_split = (char ***)malloc(sizeof(char **) * (argc - 1));
	if (argv_split == NULL)
		exit(1);
	argv_idx = 0;
	while (++argv_idx < argc)
	{
		argv_split[argv_idx - 1] = ft_split(argv[argv_idx], ' ');
		if (argv_split[argv_idx - 1] == NULL || argv[argv_idx][0] == '\0')
		{
			if (argv[argv_idx][0] == '\0')
				write(2, "Error\n", 6);
			while (--argv_idx != 0)
				free(argv_split[argv_idx - 1]);
			free(argv_split);
			exit(1);
		}
	}
	return (argv_split);
}

void	check_non_numeric_character(int argc, char ***argv_split)
{
	int		argv_idx;
	int		split_idx;
	int		idx;

	argv_idx = -1;
	while (++argv_idx < argc - 1)
	{
		split_idx = -1;
		while (argv_split[argv_idx][++split_idx] != NULL)
		{
			idx = 0;
			if (argv_split[argv_idx][split_idx][idx] == '-'
				|| argv_split[argv_idx][split_idx][idx] == '+')
				if (argv_split[argv_idx][split_idx][idx + 1] == '\0')
					error_print(argc, argv_split, 1);
			while (argv_split[argv_idx][split_idx][++idx] != '\0')
				if ('0' > argv_split[argv_idx][split_idx][idx]
					|| argv_split[argv_idx][split_idx][idx] > '9')
					error_print(argc, argv_split, 1);
		}
	}
}

int	count_total_numeric_input(int argc, char ***argv_split)
{
	int	argv_idx;
	int	input_count;
	int	split_idx;

	argv_idx = -1;
	input_count = 0;
	while (++argv_idx < argc - 1)
	{
		split_idx = -1;
		while (argv_split[argv_idx][++split_idx] != NULL)
			input_count++;
	}
	return (input_count);
}

int	*make_array_use_to_check(int input_count, int argc, char ***argv_split)
{
	int	*sorted_input;
	int	a_idx;
	int	st_idx;
	int	sp_idx;

	sorted_input = (int *)malloc(sizeof(int) * input_count);
	if (sorted_input == NULL)
		error_print(argc, argv_split, 0);
	a_idx = -1;
	st_idx = -1;
	while (++a_idx < argc - 1)
	{
		sp_idx = -1;
		while (argv_split[a_idx][++sp_idx] != NULL)
		{
			sorted_input[++st_idx] = ft_atoi_int(argv_split[a_idx][sp_idx]);
			if (sorted_input[st_idx] == 0
				&& argv_split[a_idx][sp_idx][0] != '0')
			{
				free(sorted_input);
				error_print(argc, argv_split, 1);
			}
		}
	}
	return (sorted_input);
}
