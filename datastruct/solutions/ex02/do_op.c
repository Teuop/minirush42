/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:21:10 by sbenning          #+#    #+#             */
/*   Updated: 2015/01/23 16:20:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

static int		do_add(int av1, int av3)
{
	return (av1 + av3);
}

static int		do_sub(int av1, int av3)
{
	return (av1 - av3);
}

static int		do_mul(int av1, int av3)
{
	return (av1 * av3);
}

static int		do_div(int av1, int av3)
{
	return (av3 ? (av1 / av3) : 0);
}
/*
static int		do_mod(int av1, int av3)
{
	return (av3 ? (av1 % av3) : 0);
}
*/
static void init(t_func op[])
{
	op[0] = do_add;
	op[1] = do_sub;
	op[2] = do_mul;
	op[3] = do_div;
}

static int		ichr(char *cs, char c)
{
	char	*f;

	f = ft_strchr(cs, c);
	return (f ? f - cs : -1);
}

int	main(int ac, char **av)
{
	t_func		op[CHARSET_LEN];
	int			res;

	res = 0;
	if (ac != 4)
		return (-1);
	init(op);
	if ((res = ichr(CHARSET, av[2][0])) < 0)
		return (-1);
	res = op[res](ft_atoi(av[1]), ft_atoi(av[3]));
	ft_putnbr(res);
	return (0);
}
