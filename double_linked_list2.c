#include <double_linked_list.h>

void dll_add_front(t_dll *dll, t_dllnode *node, t_dllnode *new)
{
	if (dll_is_in(dll, node) == true)
	{
		node->front->back = new;
		new->front = node->front;
		new->back = node;
		node->front = new;
		dll->size++;
	}
}

void dll_add_back(t_dll *dll, t_dllnode *node, t_dllnode *new)
{
	if (dll_is_in(dll, node) == true)
	{
		node->back->front = new;
		new->front = node;
		new->back = node->back;
		node->back = new;
		dll->size++;
	}
}

void dll_swap_node(t_dllnode *node1, t_dllnode *node2)
{
	void *temp;

	temp = node1->contents;
	node1->contents = node2->contents;
	node2->contents = temp;
}

void dll_clear(t_dll *dll, void (*del)(void *))
{
	t_dllnode *delete;
	t_dllnode *next_node;

	next_node = dll->head.back;
	while (next_node != &(dll->tail))
	{
		delete = next_node;
		next_node = next_node->back;
		del(delete->contents);
		free(delete);
	}
	dll_init(dll);
}

t_dllnode *dll_new_node(void *contents)
{
	t_dllnode *result;

	result = (t_dllnode *)malloc(sizeof(t_dllnode));
	if (result == NULL)
		return (NULL);
	result->contents = contents;
	result->front = NULL;
	result->back = NULL;
	return (result);
}

