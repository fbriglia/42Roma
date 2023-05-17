#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef	struct	s_list
{
	t_list	*preview;
    int		num; 
    int		pos;
	int 	rank;
	int		total; 
	t_list	*next; 
}				t_list;

#endif