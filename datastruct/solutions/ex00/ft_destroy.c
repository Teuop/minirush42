/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:35:14 by sbenning          #+#    #+#             */
/*   Updated: 2015/01/23 16:35:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_destroy(int ***factory)
{
	size_t		i;

	i = 0;
	while ((*factory)[i])
	{
		free((*factory)[i]);
		(*factory)[i] = NULL;
		++i;
	}
	free(*factory);
	*factory = NULL;
}

int			main(void)
{
	int		**tab;
	size_t	i;

	tab = malloc(sizeof(int *) * 4);
	if (tab == NULL)
		return (-1);
	tab[3] = NULL;
	i = 0;
	while (i < 3)
	{
		tab[i] = malloc(sizeof(int) * 2);
		if (tab[i] == NULL)
		{
			while (i > -1)
				free(tab[i--]);
			free(tab);
			return (-1);
		}
		++i;
	}
	ft_destroy(&tab);
	return (!tab ? (write(1, "OK\n", 3)) : (write(1, "KO\n", 3)));
}
