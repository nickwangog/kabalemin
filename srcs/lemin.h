/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:31:59 by nwang             #+#    #+#             */
/*   Updated: 2018/05/26 15:28:01 by lkaba            ###   ########.fr       */
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
# include "../libft/includes/ft_printf.h"
# define NUM(c) ((c) - '0')
# define C_RED		"\x1b[31m"
# define C_GRN		"\x1b[32m"
# define C_YEL		"\x1b[33m"
# define C_BLU		"\x1b[34m"
# define C_MAG		"\x1b[35m"
# define C_CYN		"\x1b[36m"
# define C_WHT		"\x1b[37m"
# define C_RESET	"\x1b[0m"

typedef struct s_rooms	t_rooms;
typedef struct s_lem	t_lem;
typedef struct s_conn	t_conn;
typedef struct s_path	t_path;

struct			s_rooms
{
	char		*name;
	int			num;
	t_lem		*ant;
	int16_t		x;
	int16_t		y;
	t_rooms		*next;
	int8_t		visited;
	int8_t		id_ant;
	int16_t		room_id;
	t_path		*path;
};

struct			s_path
{
	t_rooms		*link_room;
	t_path		*next;
};

struct			s_lem
{
	t_rooms		*head;
	t_rooms		*room;
	t_rooms		*a;
	t_rooms		*b;
	char		**tab;
	int16_t		ant_num;
	int8_t		start;
	int8_t		end;
	char		*sr_name;
	char		*er_name;
	int16_t		num_room;
	char		*line;
	int16_t		links;
};

void			read_lemin(t_lem *lem);
void			lem_error(char *s);
void			create_room(t_lem *lem);
int				countspace(char *s);
void			create_link(t_lem *lem);
void			add_link(t_lem *lem);
#endif
