/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:41:13 by sbenning          #+#    #+#             */
/*   Updated: 2015/01/23 16:42:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_line.h"

void	tr_sort_add(t_node **root, t_node *node, t_func sort)
{
	if (!*root)
		*root = node;
	else if (sort((*root)->data, node->data))
	{
		if ((*root)->right_son)
			return (tr_sort_add(&(*root)->right_son, node, sort));
		node->father = *root;
		(*root)->right_son = node;
	}
	else
	{
		if ((*root)->left_son)
			return (tr_sort_add(&(*root)->left_son, node, sort));
		node->father = *root;
		(*root)->left_son = node;
	}
}

t_node	*tr_new(t_data *data)
{
	t_node			*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->father = NULL;
	node->right_son = NULL;
	node->left_son = NULL;
	node->data = data ? data : NULL;
	return (node);
}

void	print_inf(t_node *root)
{
	if (root->left_son)
		print_inf(root->left_son);
	ft_putendl(root->data->line);
	ft_putnbr(root->data->pos);
	write(1, "\n", 1);
	ft_putnbr(root->data->size);
	write(1, "\n", 1);
	if (root->right_son)
		print_inf(root->right_son);
}
