/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarrowkey.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:51:15 by gbarraul          #+#    #+#             */
/*   Updated: 2015/01/15 19:06:22 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETARROWKEY_H
# define GETARROWKEY_H

# include <termios.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/ioctl.h>

int			getarrowkey(void);

#endif
