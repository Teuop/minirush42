/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarrowkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:49:49 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/15 19:08:07 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getarrowkey.h"

static int	kbhit(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return (1);
	}
	return (0);
}

int			getarrowkey(void)
{
	struct termios	line_police;
	char			c;
	int				d;

	if (ioctl(0, TIOCGETA, &line_police) < 0)
		1 ? (perror("getarrowkey error\n"), exit(1)) : 0;
	if (line_police.c_lflag &= ~(ICANON | ECHO))
		if ((ioctl(0, TIOCSETA, &line_police)) < 0)
			1 ? (perror("getarrowkey error\n"), exit(1)) : 0;
	if ((d = 0), kbhit())
		while ((c = fgetc(stdin)))
		{
			d = (c == 68 ? 1 : d);
			d = (c == 65 ? 2 : d);
			d = (c == 66 ? 3 : d);
			d = (c == 67 ? 4 : d);
			if (d)
				return (d);
		}
	return (0);
}
