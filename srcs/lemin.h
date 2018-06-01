/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:31:59 by nwang             #+#    #+#             */
/*   Updated: 2018/05/31 18:01:52 by lkaba            ###   ########.fr       */
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
# include "../libft/includes/ft_printf.h"
# define C_RED		"\x1b[31m"
# define C_GRN		"\x1b[32m"
# define C_YEL		"\x1b[33m"
# define C_BLU		"\x1b[34m"
# define C_MAG		"\x1b[35m"
# define C_CYN		"\x1b[36m"
# define C_WHT		"\x1b[37m"
# define C_RESET	"\x1b[0m"
# define INF 2147483647

typedef struct s_rooms	t_rooms;
typedef struct s_lem	t_lem;
typedef struct s_conn	t_conn;
typedef struct s_path	t_path;
typedef struct s_node	t_node;
typedef struct s_queue	t_queue;

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
	int32_t		num_links;
};

struct			s_path
{
	t_rooms		*link_room;
	t_path		*next;
};

struct			s_node
{
	t_rooms		*room_data;
	t_node		*next;
};

typedef struct s_queue
{
	t_node		*front;
	t_node		*rear;
}				t_queue;

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
	t_rooms		*sr;
	t_rooms		*er;
	int16_t		num_room;
	char		*line;
	int16_t		links;
	uint32_t	**dist;
	uint32_t	**shortest;
	char		buf[30000];
};

/* typedef struct t_queue
{
	t_rooms *start;
} */

void			read_lemin(t_lem *lem);
void			lem_error(char *s);
void			create_room(t_lem *lem);
int				countspace(char *s);
void			create_link(t_lem *lem);
void			add_link(t_lem *lem);
void        	dijkstra(t_lem *lem, int16_t start);
void			dijk_init(t_lem *lem);
void			print_lemin(t_lem *lem);
int 			is_no_rlinks(t_rooms *head, char *room_name);
int				is_valid_start_end(t_lem *lem);
void			sort_path(t_path **tmp, t_lem *lem);
void			move_ants(t_lem *lem);
#endif
