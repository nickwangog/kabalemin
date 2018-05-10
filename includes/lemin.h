/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:31:59 by nwang             #+#    #+#             */
/*   Updated: 2018/05/02 00:21:48 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/ft_printf.h"
# define C_RED		"\x1b[31m"
# define C_GRN		"\x1b[32m"
# define C_YEL		"\x1b[33m"
# define C_BLU		"\x1b[34m"
# define C_MAG		"\x1b[35m"
# define C_CYN		"\x1b[36m"
# define C_WHT		"\x1b[37m"
# define C_RESET	"\x1b[0m"

typedef struct		s_rooms
{
	char			*name;
	int				num;
	int				start;
	int				end;
}

typedef struct		s_lem
{
	int				ant_num;
}					t_lem;

#endif
