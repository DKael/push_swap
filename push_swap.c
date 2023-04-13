#include "push_swap.h"

void sa(t_dll *a)
{
	write(1, "sa\n", 3);
	if (a->size >= 2)
		dll_swap_node(a->head.back, a->head.back->back);
}

void sb(t_dll *b)
{
	write(1, "sb\n", 3);
	if (b->size >= 2)
		dll_swap_node(b->head.back, b->head.back->back);
}

void ss(t_dll *a, t_dll *b)
{
	write(1, "ss\n", 3);
	if (a->size >= 2)
		dll_swap_node(a->head.back, a->head.back->back);
	if (b->size >= 2)
		dll_swap_node(b->head.back, b->head.back->back);
}

void pa(t_dll *a, t_dll *b)
{
	t_dllnode *temp;

	write(1, "pa\n", 3);
	if (b->size >= 2)
	{
		temp = b->head.back;
		b->head.back->back->front = &(b->head);
		b->head.back = b->head.back->back;
		dll_add_head(a, temp);
		b->size--;
	}
	else if (b->size == 1)
	{
		temp = b->head.back;
		dll_add_head(a, temp);
		dll_init(b);
	}
}

void pb(t_dll *a, t_dll *b)
{
	t_dllnode *temp;

	write(1, "pb\n", 3);
	if (a->size >= 2)
	{
		temp = a->head.back;
		a->head.back->back->front = &(a->head);
		a->head.back = a->head.back->back;
		dll_add_head(b, temp);
		a->size--;
	}
	else if (a->size == 1)
	{
		temp = a->head.back;
		dll_add_head(b, temp);
		dll_init(a);
	}
}

void ra(t_dll *a)
{
	t_dllnode *temp;

	write(1, "ra\n", 3);
	if (a->size >= 2)
	{
		temp = a->head.back;
		a->head.back->back->front = &(a->head);
		a->head.back = a->head.back->back;
		a->size--;
		dll_add_tail(a, temp);
	}
}

void rb(t_dll *b)
{
	t_dllnode *temp;

	write(1, "rb\n", 3);
	if (b->size >= 2)
	{
		temp = b->head.back;
		b->head.back->back->front = &(b->head);
		b->head.back = b->head.back->back;
		b->size--;
		dll_add_tail(b, temp);
	}
}

void rr(t_dll *a, t_dll *b)
{
	t_dllnode *temp;

	write(1, "rr\n", 3);
	if (a->size >= 2)
	{
		temp = a->head.back;
		a->head.back->back->front = &(a->head);
		a->head.back = a->head.back->back;
		a->size--;
		dll_add_tail(a, temp);
	}
	if (b->size >= 2)
	{
		temp = b->head.back;
		b->head.back->back->front = &(b->head);
		b->head.back = b->head.back->back;
		b->size--;
		dll_add_tail(b, temp);
	}
}

void rra(t_dll *a)
{
	t_dllnode *temp;

	write(1, "rra\n", 4);
	if (a->size >= 2)
	{
		temp = a->tail.front;
		a->tail.front->front->back = &(a->tail);
		a->tail.front = a->tail.front->front;
		a->size--;
		dll_add_head(a, temp);
	}
}

void rrb(t_dll *b)
{
	t_dllnode *temp;

	write(1, "rrb\n", 4);
	if (b->size >= 2)
	{
		temp = b->tail.front;
		b->tail.front->front->back = &(b->tail);
		b->tail.front = b->tail.front->front;
		b->size--;
		dll_add_head(b, temp);
	}
}

void rrr(t_dll *a, t_dll *b)
{
	t_dllnode *temp;

	write(1, "rrr\n", 4);
	if (a->size >= 2)
	{
		temp = a->tail.front;
		a->tail.front->front->back = &(a->tail);
		a->tail.front = a->tail.front->front;
		a->size--;
		dll_add_head(a, temp);
	}
	if (b->size >= 2)
	{
		temp = b->tail.front;
		b->tail.front->front->back = &(b->tail);
		b->tail.front = b->tail.front->front;
		b->size--;
		dll_add_head(b, temp);
	}
}