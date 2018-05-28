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

t_rooms *minDistance(uint32_t *dist, uint32_t *shortest, int num_room, t_rooms *head)
{
	uint32_t min;
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

void	dijk_init(t_lem *lem)
{
	int16_t i;
	i = 0;
	lem->dist = (uint32_t **)malloc(sizeof(uint32_t *) * lem->num_room);
	lem->shortest = (uint32_t **)malloc(sizeof(uint32_t *) * lem->num_room);
	while (i < lem->num_room)
	{
		lem->dist[i] = (uint32_t *)malloc(sizeof(uint32_t) * lem->num_room);
		lem->shortest[i] = (uint32_t *)malloc(sizeof(uint32_t) * lem->num_room);
		i++;
	}
	//loop
	dijkstra(lem, 0);
	i = 0;
	while (i < lem->num_room)
	{
		ft_putnbr(i);
		ft_putstr(" :");
		ft_putnbr(lem->dist[0][i]);
		ft_putchar('\n');
		i++;
	}
}

void dijkstra(t_lem *lem, int16_t room_id)
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

