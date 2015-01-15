/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarrowkey.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:51:15 by gbarraul          #+#    #+#             */
/*   Updated: 2015/01/15 16:52:25 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETARROWKEY_H
# define FT_GETARROWKEY_H

# include <termios.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/ioctl.h>

int			getarrowkey(void);

#endif
