/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:58:12 by nwang             #+#    #+#             */
/*   Updated: 2018/06/04 14:58:56 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms			*check_r(uint32_t *dist, uint32_t *shortest, int num_room, t_rooms *head)
{
	uint32_t	min;
	int			i;
	int			room_id;

	i = 0;
	min = INF;
	while (i < num_room)
	{
		if (shortest[i] == 0 && dist[i] <= min)
		{
			min = dist[i];
			room_id = i;
		}
		i++;
	}
	while (head)
	{
		if (head->room_id == room_id)
			return (head);
		head = head->next;
	}
	return (head);
}

void			dijk_init(t_lem *lem)
{
	int16_t		i;
	t_rooms		*tmp;
	
	i = 0;
	lem->dist = (uint32_t **)malloc(sizeof(uint32_t *) * lem->num_room);
	lem->shortest = (uint32_t **)malloc(sizeof(uint32_t *) * lem->num_room);
	while (i < lem->num_room)
	{
		lem->dist[i] = (uint32_t *)malloc(sizeof(uint32_t) * lem->num_room);
		lem->shortest[i] = (uint32_t *)malloc(sizeof(uint32_t) * lem->num_room);
		i++;
	}
	tmp = lem->head;
	while (tmp)
	{
		dijkstra(lem, tmp->room_id);
		tmp = tmp->next;
	}
	tmp = lem->head;
	while (tmp)
	{
		sort_path(&tmp->path, lem);
		tmp = tmp->next;
	}
}

void			dijkstra(t_lem *lem, int16_t room_id)
{
	t_rooms		*r_check;
	t_path		*p;
	int			i;

	i = 0;
	while (i < lem->num_room)
	{
		lem->dist[room_id][i] = INF;
		lem->shortest[room_id][i] = 0;
		i++;
	}
	lem->dist[room_id][room_id] = 0;
	i = 0;
	while (i < lem->num_room)
	{
		r_check = check_r(lem->dist[room_id], lem->shortest[room_id], lem->num_room, lem->head);
		lem->shortest[room_id][r_check->room_id] = 1;
		p = r_check->path;
		while (p)
		{
			if (!lem->shortest[room_id][p->link_room->room_id] && lem->dist[room_id][r_check->room_id] != INF
					&& lem->dist[room_id][r_check->room_id] + 1 < lem->dist[room_id][p->link_room->room_id])
				lem->dist[room_id][p->link_room->room_id] = lem->dist[room_id][r_check->room_id] + 1;
			p = p->next;
		}
		i++;
	}
}

/* int8_t is_endroom(t_lem * lem)
{
	
	i = 0;
	t_rooms		*temp;
	while(i < lem->num_room)
	{
		temp = lem->head;
		while(temp)
		{
			bfs(lem, temp);
			temp = temp->next;
		}
		
	}
}

void bfs(t_lem *lem, t_rooms *t)
{
	t_queue		*q;
	t_path		*p;
	int16_t		i;
	q = init(q);
} */
