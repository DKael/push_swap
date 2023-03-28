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
		// make stack A and B by using dll
		t_dll A;
		t_dll B;
		t_dllnode *dtemp;
		int *ctemp;

		idx = -1;
		dll_init(&A);
		dll_init(&B);
		while (++idx < input_count)
		{
			ctemp = (int *)malloc(sizeof(int) * 1);
			if (dtemp == NULL)
			{
				dll_clear(&A, remove_contents);
				array_free(argc, argv_split);
			}
			*ctemp = sorted_input[idx];
			dtemp = dll_new_node(ctemp);
			if (dtemp == NULL)
			{
				dll_clear(&A, remove_contents);
				array_free(argc, argv_split);
			}
			dll_add_tail(&A, dtemp);
		}

		// printf("\n");
		// dtemp = A.head.back;
		// while (dtemp != &(A.tail))
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
				dll_clear(&A, remove_contents);
				error_print(argc, argv_split, 1);
			}
		}
		for (int i = 0; i < input_count; i++)
			printf("%d ", sorted_input[i]);
		// get two pivot
		int pivot1;
		int pivot2;

		pivot1 = sorted_input[input_count / 3];
		pivot2 = sorted_input[input_count * 2 / 3];
		printf("\n%d %d\n", pivot1, pivot2);

		// do push_swap
		int temp;
		idx = 0;
		while (++idx <= input_count)
		{
			temp = *((int *)A.head.back->contents);
			if (temp > pivot2)
				ra(&A);
			else if (pivot1 < temp && temp <= pivot2)
				pb(&A, &B);
			else
			{
				pb(&A, &B);
				rb(&B);
			}
		}

		while (A.size != 0)
			pb(&A, &B);

		int minimum;
		int maximum;

		pa(&A, &B);
		pa(&A, &B);
		if (dll_node_compare(A.head.back, A.tail.front, compare_func))
			sa(&A);
		minimum = *(int *)A.head.back->contents;
		maximum = *(int *)A.tail.front->contents;
		while (B.size != 0)
		{
			if (dll_node_compare(A.head.back, B.head.back, compare_func))
			{
				if (dll_node_compare(A.tail.front, B.head.back, compare_func))
				{
					if (maximum == *(int *)A.head.back->contents)
					{
						pa(&A, &B);
						maximum = *(int *)A.head.back->contents;
					}
					else
						rra(&A);
				}
				else
					pa(&A, &B);
			}
			else
			{
				if (!dll_node_compare(A.tail.front, B.head.back, compare_func))
				{
					if (minimum == *(int *)A.head.back->contents)
					{
						pa(&A, &B);
						minimum = *(int *)A.head.back->contents;
					}
					else
						ra(&A);
				}
				else
					pa(&A, &B);
			}
		}

		printf("\nA stack : ");
		dtemp = A.head.back;
		while (dtemp != &(A.tail))
		{
			printf("%d ", *(int *)dtemp->contents);
			dtemp = dtemp->back;
		}

		printf("\nB stack : ");
		dtemp = B.head.back;
		while (dtemp != &(B.tail))
		{
			printf("%d ", *(int *)dtemp->contents);
			dtemp = dtemp->back;
		}

		// list free part
		free(sorted_input);
		array_free(argc, argv_split);
		dll_clear(&A, remove_contents);
		dll_clear(&B, remove_contents);
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