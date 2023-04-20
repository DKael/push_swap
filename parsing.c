/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:34:30 by hyungdki          #+#    #+#             */
/*   Updated: 2023/04/20 15:34:31 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include "libft/ft_atoi_int.c"

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
		if (argv_split[argv_idx - 1] == NULL)
		{
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
	char	temp;

	argv_idx = -1;
	while (++argv_idx < argc - 1)
	{
		split_idx = -1;
		while (argv_split[argv_idx][++split_idx] != NULL)
		{
			idx = 0;
			temp = argv_split[argv_idx][split_idx][idx];
			if (temp == '-' || temp == '+')
			{
				temp = argv_split[argv_idx][split_idx][idx + 1];
				if (temp == '\0')
					error_print(argc, argv_split, 1);
			}
			while (argv_split[argv_idx][split_idx][++idx] != '\0')
				if ('0' > temp || temp > '9')
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

int	is_sorted(int input_count, int *sorted_input)
{
	int	is_sorted;
	int	idx;

	is_sorted = 1;
	idx = -1;
	while (++idx < input_count - 1)
	{
		if (sorted_input[idx] >= sorted_input[idx + 1])
		{
			is_sorted = 0;
			break ;
		}
	}
	if (is_sorted == 1)
		return (1);
	else
		return (0);
}
