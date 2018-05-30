/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:58:12 by nwang             #+#    #+#             */
/*   Updated: 2018/05/29 19:44:28 by lkaba            ###   ########.fr       */
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
	i = 0;
	while(i < lem->num_room)
		dijkstra(lem, i++);
	int j = -1;
	while(++j < lem->num_room)
	{
		i = 0;
		while (i < lem->num_room)
		{
			ft_printf("[%d][%d]", j, i);
			ft_putstr(" dist :");
			ft_putnbr(lem->dist[j][i]);
			ft_putchar('\n');
			i++;
		}
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

/* void move_ants(t_lem *lem)
{	
	int min;
	//t_rooms *temp;
	
	//temp = head;
	min = INF;
	if(lem->ant_num <= lem->dist[lem->sr->room_id][lem->er->room_id])
	{
		while ()
			if(lem->dist[lem->sr->path->link_room->room_id][lem->er->room_id] < lem->dist[lem->sr->path->link_room->next->room_id][lem->er->room_id])
				min = lem->dist[lem->sr->path->link_room->room_id][lem->er->room_id];
			else
				min = lem->dist[lem->sr->path->link_room->->next->room_id][lem->er->room_id];
		//track room ids and move ants along the way

		t_romm * 
		
	}
} */
