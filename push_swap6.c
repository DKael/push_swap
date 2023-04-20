#include "push_swap.h"

void finish_step(t_dll *a)
{
	int cliff;
	t_dllnode *a_node;

	a_node = a->head.back;
	if (*(int *)a_node->contents > *(int *)a->tail.front->contents)
	{
		cliff = 1;
		a_node = a->head.back;
		while (*(int *)a_node->contents < *(int *)a_node->back->contents)
		{
			cliff++;
			a_node = a_node->back;
		}
		if (cliff * 2 < a->size)
		{
			while (cliff-- != 0)
				ra(a);
		}
		else
		{
			while (cliff++ != a->size)
				rra(a);
		}
	}
}
