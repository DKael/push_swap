#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "double_linked_list.h"
#include "libft/libft.h"
#include "quick_sort.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char ***argument_split(int argc, char **argv);
void check_non_numeric_character(int argc, char ***argv_split);
int count_total_numeric_input(int argc, char ***argv_split);
int *make_array_use_to_check(int input_count, int argc, char ***argv_split);
int is_sorted(int input_count, int *sorted_input);
void array_free(int argc, char ***argv_split);
void error_print(int argc, char ***argv_split, int flag);
void remove_contents(void *content);
void do_push_swap(int input_count, int *sorted_input);
void make_stack(t_dll *a, int input_count, int *sorted_input);
void check_duplications(t_dll *a, int input_count, int *sorted_input);
void split_by_pivot(int input_count, int *sorted_input, t_dll *a, t_dll *b);
int compare_func(t_dllnode *n1, t_dllnode *n2);
void sort_2or3(t_dll *a);
void case2(t_dll *a);
void case3(t_dll *a);
void find_minimum_rotate(t_dll *a, t_dll *b, int *a_rotate, int *b_rotate);
int find_a_check1(t_dll *a, int num);
int find_a_check2(t_dll *a, int num, t_dllnode *a_node, int a_temp);
int find_a_check3(t_dll *a, int num, t_dllnode *a_node, int a_temp);
t_r_info calc_minimum_rotate1(int a_size, int b_size, int a_idx, int b_idx);
t_r_info calc_minimum_rotate2(int a_size, int b_size, int a_idx, int b_idx);
t_r_info calc_minimum_rotate3(int a_size, int b_size, int a_idx, int b_idx);
t_r_info calc_minimum_rotate4(int a_size, int b_size, int a_idx, int b_idx);
void set_location(int *a_rotate, int *b_rotate, t_r_info info);
void do_rotate1(int a_rotate, int b_rotate, t_dll *a, t_dll *b);
void do_rotate2(int a_rotate, int b_rotate, t_dll *a, t_dll *b);
void do_rotate3(int a_rotate, int b_rotate, t_dll *a, t_dll *b);
void do_rotate4(int a_rotate, int b_rotate, t_dll *a, t_dll *b);
void do_rotate5(int a_rotate, int b_rotate, t_dll *a, t_dll *b);
void finish_step(t_dll *a);
void sa(t_dll *a);
void sb(t_dll *b);
void ss(t_dll *a, t_dll *b);
void pa(t_dll *a, t_dll *b);
void pb(t_dll *a, t_dll *b);
void ra(t_dll *a);
void rb(t_dll *b);
void rr(t_dll *a, t_dll *b);
void rra(t_dll *a);
void rrb(t_dll *b);
void rrr(t_dll *a, t_dll *b);

#endif