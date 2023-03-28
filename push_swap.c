#include "push_swap.h"

void sa(t_dll *A)
{
	write(1, "sa\n", 3);
	if (A->size >= 2)
		dll_swap_node(A->head.back, A->head.back->back);
}

void sb(t_dll *B)
{
	write(1, "sb\n", 3);
	if (B->size >= 2)
		dll_swap_node(B->head.back, B->head.back->back);
}

void ss(t_dll *A, t_dll *B)
{
	write(1, "ss\n", 3);
	if (A->size >= 2)
		dll_swap_node(A->head.back, A->head.back->back);
	if (B->size >= 2)
		dll_swap_node(B->head.back, B->head.back->back);
}

void pa(t_dll *A, t_dll *B)
{
	t_dllnode *temp;

	write(1, "pa\n", 3);
	if (B->size >= 2)
	{
		temp = B->head.back;
		B->head.back->back->front = &(B->head);
		B->head.back = B->head.back->back;
		dll_add_head(A, temp);
		B->size--;
	}
	else if (B->size == 1)
	{
		temp = B->head.back;
		dll_add_head(A, temp);
		dll_init(B);
	}
}

void pb(t_dll *A, t_dll *B)
{
	t_dllnode *temp;

	write(1, "pb\n", 3);
	if (A->size >= 2)
	{
		temp = A->head.back;
		A->head.back->back->front = &(A->head);
		A->head.back = A->head.back->back;
		dll_add_head(B, temp);
		A->size--;
	}
	else if (A->size == 1)
	{
		temp = A->head.back;
		dll_add_head(B, temp);
		dll_init(A);
	}
}

void ra(t_dll *A)
{
	t_dllnode *temp;

	write(1, "ra\n", 3);
	if (A->size >= 2)
	{
		temp = A->head.back;
		A->head.back->back->front = &(A->head);
		A->head.back = A->head.back->back;
		A->size--;
		dll_add_tail(A, temp);
	}
}

void rb(t_dll *B)
{
	t_dllnode *temp;

	write(1, "rb\n", 3);
	if (B->size >= 2)
	{
		temp = B->head.back;
		B->head.back->back->front = &(B->head);
		B->head.back = B->head.back->back;
		B->size--;
		dll_add_tail(B, temp);
	}
}

void rr(t_dll *A, t_dll *B)
{
	t_dllnode *temp;

	write(1, "rr\n", 3);
	if (A->size >= 2)
	{
		temp = A->head.back;
		A->head.back->back->front = &(A->head);
		A->head.back = A->head.back->back;
		A->size--;
		dll_add_tail(A, temp);
	}
	if (B->size >= 2)
	{
		temp = B->head.back;
		B->head.back->back->front = &(B->head);
		B->head.back = B->head.back->back;
		B->size--;
		dll_add_tail(B, temp);
	}
}

void rra(t_dll *A)
{
	t_dllnode *temp;

	write(1, "rra\n", 4);
	if (A->size >= 2)
	{
		temp = A->tail.front;
		A->tail.front->front->back = &(A->tail);
		A->tail.front = A->tail.front->front;
		A->size--;
		dll_add_head(A, temp);
	}
}

void rrb(t_dll *B)
{
	t_dllnode *temp;

	write(1, "rrb\n", 4);
	if (B->size >= 2)
	{
		temp = B->tail.front;
		B->tail.front->front->back = &(B->tail);
		B->tail.front = B->tail.front->front;
		B->size--;
		dll_add_head(B, temp);
	}
}

void rrr(t_dll *A, t_dll *B)
{
	t_dllnode *temp;

	write(1, "rrr\n", 4);
	if (A->size >= 2)
	{
		temp = A->tail.front;
		A->tail.front->front->back = &(A->tail);
		A->tail.front = A->tail.front->front;
		A->size--;
		dll_add_head(A, temp);
	}
	if (B->size >= 2)
	{
		temp = B->tail.front;
		B->tail.front->front->back = &(B->tail);
		B->tail.front = B->tail.front->front;
		B->size--;
		dll_add_head(B, temp);
	}
}