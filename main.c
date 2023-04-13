#include "double_linked_list.h"
#include "double_linked_list1.c"
#include "double_linked_list2.c"
#include "double_linked_list3.c"
// #include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "push_swap.c"
#include "libft/libft.h"
#include "libft/ft_split.c"
#include "libft/ft_strdup.c"
#include "libft/ft_strlen.c"
#include "libft/ft_atoi_int.c"
#include <unistd.h>
#include <stdlib.h>

void array_free(int argc, char ***argv_split);
void error_print(int argc, char ***argv_split, int flag);
void remove_contents(void *content);

void sorting(int *lst, int size);
void quick_sort(int *part, int left, int right);
int make_partition(int *part, int start, int end);
void swap(int *a, int *b);
int compare_func(t_dllnode *n1, t_dllnode *n2);
void sort_2or3(t_dll *a);
void case2(t_dll *a);
void case3(t_dll *a);
void find_minimum_rotate(t_dll *a, t_dll *b, int *a_rotate, int *b_rotate);
int find_a_check(t_dll *a, int num);
t_r_info calc_minimum_rotate(int a_size, int b_size, int a_idx, int b_idx);
t_r_info calc_minimum_rotate1(int a_size, int b_size, int a_idx, int b_idx);
t_r_info calc_minimum_rotate2(int a_size, int b_size, int a_idx, int b_idx);
t_r_info calc_minimum_rotate3(int a_size, int b_size, int a_idx, int b_idx);
void set_location(int *a_rotate, int *b_rotate, t_r_info info);

void print_stack(t_dll *a, t_dll *b);

#include <stdio.h>

int main(int argc, char **argv)
{
	int argv_idx;
	int split_idx;
	int idx;
	int input_count;
	char ***argv_split;
	int *sorted_input;
	int sorted_idx;
	char temp;

	if (argc != 1)
	{
		// argument split
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
		// check non numeric character
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
				{
					if ('0' > temp || temp > '9')
						error_print(argc, argv_split, 1);
				}
			}
		}
		// count total numeric input
		argv_idx = -1;
		input_count = 0;
		while (++argv_idx < argc - 1)
		{
			split_idx = -1;
			while (argv_split[argv_idx][++split_idx] != NULL)
				input_count++;
		}
		// make array use to sorting input
		sorted_input = (int *)malloc(sizeof(int) * input_count);
		if (sorted_input == NULL)
			error_print(argc, argv_split, 0);
		argv_idx = -1;
		sorted_idx = -1;
		while (++argv_idx < argc - 1)
		{
			split_idx = -1;
			while (argv_split[argv_idx][++split_idx] != NULL)
			{
				sorted_input[++sorted_idx] = ft_atoi_int(argv_split[argv_idx][split_idx]);
				if ((sorted_input[sorted_idx] == 0 && argv_split[argv_idx][split_idx][0] != '0'))
				{
					free(sorted_input);
					error_print(argc, argv_split, 1);
				}
			}
		}
		// check it is sorted
		int is_sorted;

		is_sorted = 1;
		idx = -1;
		while (++idx < input_count - 1)
		{
			if (sorted_input[idx] >= sorted_input[idx + 1])
			{
				is_sorted = 0;
				break;
			}
		}
		if (is_sorted == 1)
			return (0);

		// for (int i = 0; i < input_count; i++)
		// {
		// 	printf("%d ", sorted_input[i]);
		// }
		// make stack a and b by using dll
		t_dll a;
		t_dll b;
		t_dllnode *dtemp;
		int *ctemp;

		idx = -1;
		dll_init(&a);
		dll_init(&b);
		while (++idx < input_count)
		{
			ctemp = (int *)malloc(sizeof(int) * 1);
			if (dtemp == NULL)
			{
				dll_clear(&a, remove_contents);
				array_free(argc, argv_split);
			}
			*ctemp = sorted_input[idx];
			dtemp = dll_new_node(ctemp);
			if (dtemp == NULL)
			{
				dll_clear(&a, remove_contents);
				array_free(argc, argv_split);
			}
			dll_add_tail(&a, dtemp);
		}

		// printf("\n");
		// dtemp = a.head.back;
		// while (dtemp != &(a.tail))
		// {
		// 	printf("%d ", *(int *)dtemp->contents);
		// 	dtemp = dtemp->back;
		// }

		// array sorting
		sorting(sorted_input, input_count);

		// check duplications
		idx = -1;
		while (++idx < input_count - 1)
		{
			if (sorted_input[idx] == sorted_input[idx + 1])
			{
				dll_clear(&a, remove_contents);
				error_print(argc, argv_split, 1);
			}
		}
		for (int i = 0; i < input_count; i++)
			printf("%d ", sorted_input[i]);
		// get two pivot
		int pivot1;
		int pivot2;

		pivot1 = sorted_input[input_count / 3 - 1];
		pivot2 = sorted_input[input_count * 2 / 3 - 1];
		printf("\n%d %d\n", pivot1, pivot2);

		// do push_swap
		// split three part
		print_stack(&a, &b);

		int temp;
		idx = 0;
		while (++idx <= input_count)
		{
			temp = *((int *)a.head.back->contents);
			if (temp > pivot2)
				ra(&a);
			else if (pivot1 < temp && temp <= pivot2)
				pb(&a, &b);
			else
			{
				pb(&a, &b);
				rb(&b);
			}
		}

		print_stack(&a, &b);

		while (a.size != 3)
			pb(&a, &b);

		print_stack(&a, &b);

		sort_2or3(&a);

		print_stack(&a, &b);

		// sorting3
		int a_rotate;
		int b_rotate;
		int idx1;

		while (b.size != 0)
		{
			print_stack(&a, &b);

			a_rotate = 0;
			b_rotate = 0;

			find_minimum_rotate(&a, &b, &a_rotate, &b_rotate);
			if (a_rotate >= 0 && b_rotate >= 0)
			{
				idx1 = 0;
				if (a_rotate >= b_rotate)
				{
					while (idx1 < b_rotate)
					{
						rr(&a, &b);
						idx1++;
					}
					while (idx1 < a_rotate)
					{
						ra(&a);
						idx1++;
					}
				}
				else
				{
					while (idx1 < a_rotate)
					{
						rr(&a, &b);
						idx1++;
					}
					while (idx1 < b_rotate)
					{
						rb(&a);
						idx1++;
					}
				}
			}
			else if (a_rotate <= 0 && b_rotate <= 0)
			{
				idx1 = 0;
				a_rotate *= -1;
				b_rotate *= -1;
				if (a_rotate >= b_rotate)
				{
					while (idx1 < b_rotate)
					{
						rrr(&a, &b);
						idx1++;
					}
					while (idx1 < a_rotate)
					{
						rra(&a);
						idx1++;
					}
				}
				else
				{
					while (idx1 < a_rotate)
					{
						rrr(&a, &b);
						idx1++;
					}
					while (idx1 < b_rotate)
					{
						rrb(&a);
						idx1++;
					}
				}
			}
			else if (a_rotate >= 0 && b_rotate <= 0)
			{
				idx1 = 0;
				b_rotate *= -1;
				while (idx1 < a_rotate)
				{
					ra(&a);
					idx1++;
				}
				idx1 = 0;
				while (idx1 < b_rotate)
				{
					rrb(&b);
					idx1++;
				}
			}
			else if (a_rotate <= 0 && b_rotate >= 0)
			{
				idx1 = 0;
				a_rotate *= -1;
				while (idx1 < a_rotate)
				{
					rra(&a);
					idx1++;
				}
				idx1 = 0;
				while (idx1 < b_rotate)
				{
					rb(&b);
					idx1++;
				}
			}
			pa(&a, &b);
		}

		print_stack(&a, &b);

		// sorting2
		// int floor_count;
		// floor_count = 0;
		// idx = 0;
		// while (idx <= input_count - 3)
		// {
		// 	rra(&a);
		// 	a.head.back->is_floor = 1;
		// 	floor_count++;
		// 	pa(&a, &b);
		// 	a.head.back->is_floor = 0;
		// 	rrb(&b);
		// 	pa(&a, &b);
		// 	a.head.back->is_floor = 0;
		// 	idx += 3;
		// }
		// if (input_count % 3 == 2)
		// {
		// 	fprintf(stderr, "remain 2!");
		// 	rra(&a);
		// 	a.head.back->is_floor = 1;
		// 	floor_count++;
		// 	pa(&a, &b);
		// 	a.head.back->is_floor = 0;
		// }
		// else if (input_count % 3 == 1)
		// {
		// 	fprintf(stderr, "remain 1!");
		// 	rra(&a);
		// 	a.head.back->is_floor = 1;
		// 	floor_count++;
		// }
		// while (floor_count != 1)
		// {
		// 	rra(&a);
		// 	pb(&a, &b);
		// 	while (a.tail.front->is_floor != 1)
		// 	{
		// 		rra(&a);
		// 		pb(&a, &b);
		// 		rb(&b);
		// 	}
		// 	if (dll_node_compare(a.tail.front, b.head.back, compare_func))
		// 	{
		// 		rra(&a);
		// 		b.head.back->is_floor = 0;
		// 	}
		// 	else
		// 	{
		// 		pa(&a, &b);
		// 		a.tail.front->is_floor = 0;
		// 	}
		// 	while (a.tail.front->is_floor != 1 && b.size != 0)
		// 	{
		// 		if (dll_node_compare(a.tail.front, b.head.back, compare_func))
		// 			rra(&a);
		// 		else
		// 			pa(&a, &b);
		// 	}
		// 	if (a.tail.front->is_floor == 1)
		// 	{
		// 		while (b.size != 0)
		// 			pa(&a, &b);
		// 	}
		// 	else if (b.size == 0)
		// 	{
		// 		while (a.tail.front->is_floor != 1)
		// 			rra(&a);
		// 	}
		// 	floor_count--;
		// }

		// sorting1
		//  while (a.size != 0)
		//  	pb(&a, &b);
		//  int cur_idx;
		//  cur_idx = 0;
		//  pa(&a, &b);
		//  pa(&a, &b);
		//  if (dll_node_compare(a.head.back, a.tail.front, compare_func))
		//  	sa(&a);
		//  while (b.size != 0)
		//  {
		//  	if (!dll_node_compare(b.head.back, b.head.back->back, compare_func))
		//  		sb(&b);
		//  	if (dll_node_compare(a.head.back, b.head.back, compare_func))
		//  	{
		//  		if (dll_node_compare(a.tail.front, b.head.back, compare_func))
		//  		{
		//  			if (dll_node_compare(a.tail.front, a.head.back, compare_func))
		//  				pa(&a, &b);
		//  			else
		//  				rra(&a);
		//  		}
		//  		else
		//  			pa(&a, &b);
		//  	}
		//  	else
		//  	{
		//  		if (!dll_node_compare(a.tail.front, b.head.back, compare_func))
		//  		{
		//  			if (dll_node_compare(a.tail.front, a.head.back, compare_func))
		//  				pa(&a, &b);
		//  			else
		//  				ra(&a);
		//  		}
		//  		else
		//  			ra(&a);
		//  	}
		//  }
		//  while (!dll_node_compare(a.tail.front, a.head.back, compare_func))
		//  	ra(&a);

		// list free part
		free(sorted_input);
		array_free(argc, argv_split);
		dll_clear(&a, remove_contents);
		dll_clear(&b, remove_contents);
	}
}

void print_stack(t_dll *a, t_dll *b)
{
	t_dllnode *dtemp;

	fprintf(stderr, "\na stack : ");
	dtemp = a->head.back;
	while (dtemp != &(a->tail))
	{
		fprintf(stderr, "%d ", *(int *)dtemp->contents);
		dtemp = dtemp->back;
	}

	fprintf(stderr, "\nb stack : ");
	dtemp = b->head.back;
	while (dtemp != &(b->tail))
	{
		fprintf(stderr, "%d ", *(int *)dtemp->contents);
		dtemp = dtemp->back;
	}
}

void array_free(int argc, char ***argv_split)
{
	int argv_idx;
	int split_idx;

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

void error_print(int argc, char ***argv_split, int flag)
{
	if (flag == 1)
		write(1, "Error\n", 6);
	array_free(argc, argv_split);
	exit(1);
}

void remove_contents(void *content)
{
	free(content);
}

void sorting(int *lst, int size)
{
	quick_sort(lst, 0, size - 1);
}

void quick_sort(int *part, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = make_partition(part, left, right);
		quick_sort(part, left, pivot - 1);
		quick_sort(part, pivot + 1, right);
	}
}

int make_partition(int *part, int start, int end)
{
	int pivot;
	int head;
	int tail;

	pivot = start;
	head = start;
	tail = end + 1;
	while (head < tail)
	{
		while (++head < end && part[head] < part[pivot])
			;
		while (--tail > start && part[tail] > part[pivot])
			;
		if (head < tail)
			swap(&part[head], &part[tail]);
	}
	swap(&part[pivot], &part[tail]);
	return (tail);
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int compare_func(t_dllnode *n1, t_dllnode *n2)
{
	if (*(int *)n1->contents > *(int *)n2->contents)
		return (1);
	else
		return (0);
}

void sort_2or3(t_dll *a)
{
	if (a->size == 2)
		case2(a);
	else if (a->size == 3)
		case3(a);
}

void case2(t_dll *a)
{
	int num1;
	int num2;

	num1 = *(int *)(a->head.back->contents);
	num2 = *(int *)(a->tail.front->contents);
	if (num1 > num2)
		sa(a);
}

void case3(t_dll *a)
{
	int num1;
	int num2;
	int num3;

	num1 = *(int *)(a->head.back->contents);
	num2 = *(int *)(a->head.back->back->contents);
	num3 = *(int *)(a->tail.front->contents);
	if (num1 > num2 && num3 > num1 && num3 > num2)
		sa(a);
	else if (num1 > num2 && num1 > num3 && num3 > num2)
		ra(a);
	else if (num2 > num1 && num2 > num3 && num1 > num3)
		rra(a);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		sa(a);
		rra(a);
	}
	else if (num2 > num1 && num2 > num3 && num3 > num1)
	{
		sa(a);
		ra(a);
	}
}

void find_minimum_rotate(t_dll *a, t_dll *b, int *a_rotate, int *b_rotate)
{
	int a_check;
	int b_check;
	t_dllnode *b_node;
	int min_rotate;
	t_r_info cur_pos_info;

	b_check = 0;
	b_node = b->head.back;
	min_rotate = INT_MAX;
	while (b_check < b->size)
	{
		a_check = find_a_check(a, *(int *)b_node->contents);
		cur_pos_info = calc_minimum_rotate(a->size, b->size, a_check, b_check);
		if (cur_pos_info.calc_rotate < min_rotate)
		{
			cur_pos_info.a_check = a_check;
			cur_pos_info.b_check = b_check;
			cur_pos_info.a_size = a->size;
			cur_pos_info.b_size = b->size;
			set_location(a_rotate, b_rotate, cur_pos_info);
			min_rotate = cur_pos_info.calc_rotate;
		}
		b_node = b_node->back;
		b_check++;
	}
}

int find_a_check(t_dll *a, int num)
{
	t_dllnode *a_node;
	int a_temp;

	a_temp = 0;
	a_node = a->head.back;
	if (num < *(int *)a_node->contents)
		return (0);
	else if (num > *(int *)a->tail.front->contents)
		return (a->size);
	else
	{
		while (a_temp + 1 < a->size)
		{
			if (*(int *)a_node->contents < num && num < *(int *)a_node->back->contents)
				return (a_temp + 1);
			a_node = a_node->back;
			a_temp++;
		}
	}
}

t_r_info calc_minimum_rotate(int a_size, int b_size, int a_idx, int b_idx)
{
	t_r_info info;

	if (a_idx * 2 < a_size && b_idx * 2 < b_size)
	{
		if (a_idx >= b_idx)
			info.calc_rotate = a_idx;
		else
			info.calc_rotate = b_idx;
		info.flag = 1;
	}
	else if (a_idx * 2 >= a_size && b_idx * 2 >= b_size)
	{
		if (a_size - a_idx >= b_size - b_idx)
			info.calc_rotate = a_size - a_idx;
		else
			info.calc_rotate = b_size - b_idx;
		info.flag = 2;
	}
	else
		return (calc_minimum_rotate1(a_size, b_size, a_idx, b_idx));
	return (info);
}

t_r_info calc_minimum_rotate1(int a_size, int b_size, int a_idx, int b_idx)
{

	if (a_idx * 2 < a_size && b_idx * 2 >= b_size)
		return (calc_minimum_rotate2(a_size, b_size, a_idx, b_idx));
	else if (a_idx * 2 >= a_size && b_idx * 2 < b_size)
		return (calc_minimum_rotate3(a_size, b_size, a_idx, b_idx));
}

t_r_info calc_minimum_rotate2(int a_size, int b_size, int a_idx, int b_idx)
{
	t_r_info info;
	int temp_calc;

	info.calc_rotate = a_idx + b_size - b_idx;
	if (b_idx < a_size - a_idx)
	{
		temp_calc = b_idx;
		info.flag = 4;
	}
	else
	{
		temp_calc = a_size - a_idx;
		info.flag = 5;
	}
	if (temp_calc < info.calc_rotate)
		info.calc_rotate = temp_calc;
	else
		info.flag = 3;
	return (info);
}

t_r_info calc_minimum_rotate3(int a_size, int b_size, int a_idx, int b_idx)
{
	t_r_info info;
	int temp_calc;

	info.calc_rotate = b_idx + a_size - a_idx;
	if (a_idx < b_size - b_idx)
	{
		temp_calc = a_idx;
		info.flag = 7;
	}
	else
	{
		temp_calc = b_size - b_idx;
		info.flag = 8;
	}

	if (temp_calc < info.calc_rotate)
		info.calc_rotate = temp_calc;
	else
		info.flag = 6;
	return (info);
}

void set_location(int *a_rotate, int *b_rotate, t_r_info info)
{
	if (info.flag == 1 || info.flag == 4 || info.flag == 7)
	{
		*a_rotate = info.a_check;
		*b_rotate = info.b_check;
	}
	else if (info.flag == 2 || info.flag == 5 || info.flag == 8)
	{
		*a_rotate = info.a_check - info.a_size;
		*b_rotate = info.b_check - info.b_size;
	}
	else if (info.flag == 3)
	{
		*a_rotate = info.a_check;
		*b_rotate = info.b_check - info.b_size;
	}
	else if (info.flag == 6)
	{
		*a_rotate = info.a_check - info.a_size;
		*b_rotate = info.b_check;
	}
}