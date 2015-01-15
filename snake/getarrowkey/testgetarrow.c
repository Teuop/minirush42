/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:00:56 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/15 16:59:51 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getarrowkey.h"

/*
** Main d'exemple pour comprendre le fonctionnement de getarrowkey
*/

int			main(void)
{
	int key;

	while (1)
	{
		key = getarrowkey();
		ft_putstr("\nKEY = ");
		if (key == 1)
			ft_putendl("LEFT");
		else if (key == 2)
			ft_putendl("UP");
		else if (key == 3)
			ft_putendl("DOWN");
		else if (key == 4)
			ft_putendl("RIGHT");
		else
			ft_putendl("nothing");
		usleep(100000);
		system("CLEAR");
	}
	return (0);
}
