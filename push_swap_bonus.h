/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:16:15 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/08 14:55:50 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "double_linked_list_bonus.h"
# include "libft/libft.h"
# include "quick_sort_bonus.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_dll_col
{
	t_dll	a;
	t_dll	b;
	t_dll	instruction;
}	t_dll_col;

char		***argument_split(int argc, char **argv);
void		check_non_numeric_character(int argc, char ***argv_split);
int			count_total_numeric_input(int argc, char ***argv_split);
int			*make_array_use_to_check(int input_count, int argc,
				char ***argv_split);
void		array_free(int argc, char ***argv_split);
void		error_print(int argc, char ***argv_split, int flag);
void		remove_contents(void *content);
void		do_push_swap1(int input_count, int *sorted_input);
void		do_push_swap2(t_dll_col *dll_col, int *sorted_input);
void		make_instr_list(t_dll *instruction);
void		make_stack(t_dll *a, int input_count, int *sorted_input);
void		check_duplications(t_dll *a, int input_count, int *sorted_input);
int			exe_instr(t_dll_col *dll_col, char *contents);
void		finish_step(t_dll_col *dll_col, int *sorted_input, int flag);
void		sa(t_dll *a);
void		sb(t_dll *b);
void		ss(t_dll *a, t_dll *b);
void		pa(t_dll *a, t_dll *b);
void		pb(t_dll *a, t_dll *b);
void		ra(t_dll *a);
void		rb(t_dll *b);
void		rr(t_dll *a, t_dll *b);
void		rra(t_dll *a);
void		rrb(t_dll *b);
void		rrr(t_dll *a, t_dll *b);

#endif
