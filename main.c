/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:32 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 23:40:56 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		input_count;
	char	***argv_split;
	int		*sorted_input;

	if (argc != 1)
	{
		argv_split = argument_split(argc, argv);
		check_non_numeric_character(argc, argv_split);
		input_count = count_total_numeric_input(argc, argv_split);
		sorted_input = make_array_use_to_check(input_count, argc, argv_split);
		array_free(argc, argv_split);
		if (is_sorted(input_count, sorted_input) == 0)
			do_push_swap1(input_count, sorted_input);
		free(sorted_input);
	}
}
