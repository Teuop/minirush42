/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:40:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/01/23 16:42:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_line.h"

static int		tr_alpha_sort(t_data *d1, t_data *d2)
{
	if (ft_strcmp(d1->line, d2->line) < 0)
		return (True);
	return (False);
}

static t_node	*sort_file(int fd)
{
	int			i;
	char		*line;
	t_data		*data;
	t_node		*node;
	t_node		*root;

	line = NULL;
	root = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		data = malloc(sizeof(t_data));
		data->line = ft_strdup(line);
		data->size = ft_strlen(line);
		data->pos = i++;
		free(line);
		line = NULL;
		node = tr_new(data);
		tr_sort_add(&root, node, tr_alpha_sort);
	}
	return (root);
}

void			main(void)
{
	int		fd;
	t_node	*root;

	fd = open("test", O_RDONLY);
	root = sort_file(fd);
	print_inf(root);
}
