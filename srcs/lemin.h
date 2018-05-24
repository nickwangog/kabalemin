/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:31:59 by nwang             #+#    #+#             */
/*   Updated: 2018/05/23 15:54:11 by lkaba            ###   ########.fr       */
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

struct			s_rooms
{
	char		*name;
	int			num;
	t_lem		*ant;
	int8_t		x;
	int8_t		y;
	t_rooms		**link;
	t_rooms		*next;
	int8_t		visited;
	int8_t		id_ant;
	int8_t		room_id;
};

struct			s_lem
{
	t_rooms		*head;
	t_rooms		*room;
	char		**tab;
	int16_t		ant_num;
	int8_t		start;
	int8_t		end;
	char		*sr_name;
	char		*er_name;
	int16_t		num_room;
	char		*line;
};

void			read_lemin(t_lem *lem);
void			lem_error(char *s);
void			parse_room(t_lem *lem);
int				countspace(char *s);
void			check_link(t_lem *lem);
#endif
