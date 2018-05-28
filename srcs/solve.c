/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:58:12 by nwang             #+#    #+#             */
/*   Updated: 2018/05/28 00:30:25 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// void        move_ants (t_lem *lem)
// {

// }

void        dijkstra(t_lem *lem)
{
	// create a shortest path set (array), keeps
	// track of vertices whose minimum distance from
	// start is calculated, empty to begin with.

	// assign all distance values as infinity, start vertex as zero

	// pick next vertex with minimun distance value, include it to the
	// shortest path set, update adjacent vertices of last picked vertex
	// , recalculate distances and weights

}

int minDistance(uint32_t *dist, uint32_t *shortest, int num_room, t_rooms *head)
{
	// Initialize min value
	int min;
	int i;

	i = 0;
	min = INF;
	int room_id;

	while (i < num_room)
	{
		if (shortest[i] == 0 && dist[i] <= min)
		{
			min = dist[i];
			room_id = i;
		}
		i++;
	}
	while(head)
	{
		if(head->room_id == room_id)
			return(head);
		head = head->next;
	}
	return (head);
}

void dijkstra(t_lem *lem, int room_id)
{

	t_rooms *r_check;
	t_path	*p;
	int i;
	i = 0;

	while(i < lem->num_room)
	{
		lem->dist[room_id][i] = INF;
		lem->shortest[room_id][i] = 0;
		i++;
	}
	lem->dist[room_id][room_id] = 0;
	i = 0;
	while(i < lem->num_room)
	{
		r_check = minDistance(lem->dist[room_id], lem->shortest[room_id], lem->num_room, lem->head);
		lem->shortest[r_check->room_id] = 1;
		p = r_check->path;
		while (p)
		{
			if (!lem->shortest[room_id][p->link_room->room_id] && lem->dist[room_id][r_check->room_id] != INF
					&& lem->dist[room_id][r_check->room_id] + 1 < lem->dist[room_id][p->link_room->room_id])
				lem->dist[room_id][p->link_room->room_id] = lem->dist[room_id][r_check->room_id] + 1;
			p = p->next;
		}

	}
}

