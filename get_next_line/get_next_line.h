#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define CLEAN_FD_ONLY	0
# define CLEAN_ALL 		1

# include <unistd.h>
# include <stdlib.h>

typedef struct s_fd_node
{
	int					fd;
	int					start;
	int					end;
	char				bf[BUFFER_SIZE];
	int					read;
	struct s_fd_node	*next;
}	t_fd_node;

typedef struct s_lnode
{
	int				size;
	char			bf[BUFFER_SIZE];
	struct s_lnode	*next;
}	t_lnode;

typedef struct s_data
{
	t_fd_node	*it;
	t_fd_node	*it_back;
	t_fd_node	**fd_start;
	t_lnode		node;
}	t_data;

char	*get_next_line(int fd);
char	*get_buffer_remains(t_data *data);
char	*case_nl_eof(t_data *data, int idx, t_fd_node *it);
char	*read_lines1(t_data *data);
char	*read_lines2(t_data *data, t_lnode **pos);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_lstclear(t_lnode **lst);
char	*do_concat(t_lnode *tstart);
void	*free_fd_and_node(t_data *data, int flag);
void	parse(t_data *data, int *idx, t_lnode **pos, t_lnode **tmake);

#endif
