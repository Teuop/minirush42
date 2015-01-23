/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:39:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/01/23 16:40:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_LINE_H
# define FT_SORT_LINE_H

# include "libft.h"
# include "get_next_line.h"

typedef struct			s_data
{
	char				*line;
	size_t				size;
	size_t				pos;
}						t_data;

typedef struct			s_node
{
	struct s_node		*father;
	struct s_node		*left_son;
	struct s_node		*right_son;
	t_data				*data;
}						t_node;

typedef enum			e_ex_bool
{
	False,
	True
}						t_ex_bool;

typedef int	(*t_func)(t_data *, t_data *);

void					tr_sort_add(t_node **root, t_node *node, p_func sort);
void					print_inf(t_node *root);
t_node					*tr_new(t_data *data);

#endif
