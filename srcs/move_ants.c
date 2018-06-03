/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:17:17 by nwang             #+#    #+#             */
/*   Updated: 2018/06/02 18:42:43 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ant_init(t_ants *ants, int16_t n, t_rooms *sr)
{
	int16_t i;

	i = -1;
	while(++i < n)
	{
		ants[i].ant_id = i;
		ants[i].ant_room = sr;
	}
}


void path_decision(t_lem *lem)
{
	int16_t temp;
	temp = 1;
	t_path *p;	
	
	p = lem->sr->path;
	lem->count = lem->sr->num_links;		
	while(lem->count--)
	{
		temp = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], temp);
		p = p->next;
	}
	lem->sum_lcm = temp;
}

void	best_lcm(t_lem *lem)
{
	while (lem->sum_lcm > lem->ant_num)
	{
		lem->count = lem->count - 1;
		path_decision(lem);
	}
	printf("lem->count value = %d | lcm =  %d\n", lem->count, lem->sum_lcm);
}

/* void move_ants(t_lem	*lem)
{
	t_ants *ants;
	ants = lem->tab_ants;
	int i;
	i = 0;
	while(i < lem->count)
	{
		if(ants[i].ant_room-
	}
	//start from ant_id 1, check if next room is unoccupied
	//change room_id associated with ant
	// subtract from lem->board_ants
	//iterate through ants to next ant id
} */

void	move_ant(t_ants *a, t_rooms *r)
{
	// set the ants last room's has_ant to 0
	// set the cur ant's current room to the * passed through here (r)
	// set the ant's new current room has_ant to 1
	// print the movement of the ant
	a->ant_room->has_ant = 0;
	a->ant_room = r;
	a->ant_room->has_ant = 1;
	lem->board_ants -= r == lem->er ? 1 : 0;
	ft_printf("L%d-%s ",a->ant_id + 1, a->ant_room->name);
	//print the space;
}

void move_ant_from_start(t-lem *lem, t_path *p, t_ant *a)
{
	int i;
	move_ant(a, );
	lem->start_ants--;
}
void lem_ants(t_lem	*lem)
{
	int16_t i;
	int16_t j;
	//int16_t temp;
	t_paths	*p;	
	t_ants ants[lem->ant_num];
	
	i = 0;
	ant_init(ants, lem->ant_num, lem->sr);
	path_decision(lem);
	lem->board_ants = lem->ant_num;
	lem->start_ants = lem->ant_num;
	while(lem->board_ants)
	{
		if(lem->sum_lcm < lem->ant_num)
		{
			i = -1;
			while(++i < lem->ant_num)
			{
				if(ants[i].ant_room->path->link_room == lem->er)
					move_ant(lem, &ants[i], lem->er);
				else if (ants[i].ant_room == lem->sr)
				{
					p = p->sr->path;

					move_ant_from_start(lem,  &ants[i]

				}
				else
				{

				}
				/* move_ants(t_lem *lem);
			move ants to the number of paths count
			subtract from ant total
			track and store ant movements to print */
		}
		else
		{
			best_lcm(lem);
		}
	}
	
	while(lem->rem_ants < lem->ant_num)
	{

	}
}