#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdlib.h>

typedef enum e_bool
{
	false, true
}	t_bool;

typedef struct s_dllnode
{
	struct s_dllnode	*front;
	struct s_dllnode	*back;
	void				*contents;
}	t_dllnode;

typedef struct s_dll
{
	t_dllnode	head;
	t_dllnode	tail;
	int			size;
}	t_dll;

typedef struct s_r_info
{
	int calc_rotate;
	int flag;
	int a_check;
	int b_check;
	int a_size;
	int b_size;
}	t_r_info;

void		dll_init(t_dll *dll);
void		dll_add_head(t_dll *dll, t_dllnode *new);
void		dll_add_tail(t_dll *dll, t_dllnode *new);
t_bool		dll_is_in(t_dll *dll, t_dllnode *check);
t_dllnode	*dll_find(t_dll *dll, void *contents, int (*f)(void *, void *));
void		dll_add_front(t_dll *dll, t_dllnode *node, t_dllnode *new);
void		dll_add_back(t_dll *dll, t_dllnode *node, t_dllnode *new);
void		dll_swap_node(t_dllnode *node1, t_dllnode *node2);
void		dll_clear(t_dll *dll, void (*del)(void *));
t_dllnode	*dll_new_node(void *contents);
void 		dll_del_node(t_dll *dll, t_dllnode *node, void (*del)(void *));

#endif