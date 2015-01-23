/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:35:45 by sbenning          #+#    #+#             */
/*   Updated: 2015/01/23 16:37:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_reverse(int **tab1, int **tab2)
{
	int		*tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

int			main(void)
{
	int		*tab1;
	int		*tab2;
	int		*tmp1;
	int		*tmp2;

	tab1 = malloc(sizeof(int) * 4);
	if (tab1 == NULL)
		return (-1);
	tab2 = malloc(sizeof(int) * 4);
	if (tab2 == NULL)
	{
		free(tab1);
		return (-1);
	}
	tmp1 = tab1;
	tmp2 = tab2;
	ft_reverse(&tab1, &tab2);
	(tmp1 == tab2 && tmp2 == tab1) ? \
		(write(1, "OK\n", 3)) : (write(1, "KO\n", 3));
	ft_destroy(&tab1);
	ft_destroy(&tab2);
	return (0);
}
