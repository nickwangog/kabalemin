/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:31:59 by nwang             #+#    #+#             */
/*   Updated: 2018/06/06 17:22:29 by lkaba            ###   ########.fr       */
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
# include <errno.h>
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
# define S_DIST lem->shortest[room_id][p->link_room->room_id]
# define D_DIST lem->dist[room_id][r_check->room_id]

typedef struct s_rooms	t_rooms;
typedef struct s_lem	t_lem;
typedef struct s_conn	t_conn;
typedef struct s_path	t_path;
typedef struct s_ants	t_ants;
typedef struct s_node	t_node;
typedef struct s_queue	t_queue;

struct				s_node
{
	t_rooms			*r;
	struct s_node	*next;
};

struct				s_queue
{
	t_node			*front;
	t_node			*rear;
};

struct				s_rooms
{
	char			*name;
	int16_t			x;
	int16_t			y;
	t_rooms			*next;
	int8_t			visited;
	int16_t			room_id;
	t_path			*path;
	int32_t			num_links;
	int8_t			has_ant;
};

struct				s_path
{
	t_rooms			*link_room;
	t_path			*next;
};

struct				s_ants
{
	int16_t			ant_id;
	t_rooms			*ant_room;
};

struct				s_lem
{
	t_rooms			*head;
	t_rooms			*room;
	t_rooms			*a;
	t_rooms			*b;
	char			**tab;
	t_rooms			*sr;
	t_rooms			*er;
	t_ants			*tab_ants;
	int16_t			count;
	int16_t			p_to_take;
	int16_t			ant_num;
	int16_t			start_ants;
	int16_t			board_ants;
	int8_t			start;
	int8_t			end;
	int8_t			space;
	int16_t			num_room;
	t_path			*p;
	t_path			*k;
	char			*line;
	int16_t			j;
	int16_t			links;
	uint32_t		**dist;
	uint32_t		**shortest;
	int16_t			sum_lcm;
	int8_t			color;
	char			buf[30000];
};

void				read_lemin(t_lem *lem);
void				lem_error(char *s);
void				create_room(t_lem *lem, t_rooms *temp, t_rooms *temp1);
int					countspace(char *s);
void				create_link(t_lem *lem);
void				add_link(t_lem *lem);
void				dijkstra(t_lem *lem, int16_t start, int i);
void				dijk_init(t_lem *lem);
int					is_no_rlinks(t_rooms *head, char *room_name);
int					is_valid_start_end(t_lem *lem);
void				sort_path(t_path **tmp, t_lem *lem);
void				lem_ants(t_lem *lem, int16_t i);
unsigned int		lcm(unsigned int a, unsigned int b);
t_queue				*init(t_queue *q);
void				enqueue(t_queue *q, t_rooms *r);
t_rooms				*dequeue(t_queue *q);
int					is_empty(t_queue *q);
void				check_endroom(t_lem *lem);
void				bfs(t_lem *lem, t_rooms *t, int16_t i);
void				best_lcm(t_lem *lem);
int16_t				path_decision(t_lem *lem);
#endif
