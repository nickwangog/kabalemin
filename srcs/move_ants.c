/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:17:17 by nwang             #+#    #+#             */
/*   Updated: 2018/06/01 18:21:40 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    move_ants(t_lem *lem)
{
	t_rooms *p;
	t_ant   ant[num_of_ants];
	//init_ant initialise all the ant to the start room
   // int16_t i;

	p = NULL;
	//move ant to shortest distance room in sorted path, check if room has an ant inside of it.
	//if number of ants is larger than the dist of [room][end], use the next path as well.
	//track and print movement of ants.
	lem->sr->ants = lem->ant_num;
	p = lem->sr->path->link_room;
	if (!p)
		return ;
	//printf("pname: %s", p->link_room);

	while(lem->sr->ants)
	{
		p = lem->sr->path->link_room;
								 p->ants == 0 ? p->ants = 1 && lem->sr->ants-- : 0;
		while(p && p->next)
		{
			p->ants == 1 && p->path == 0 ? (( p->ants = 0 ) && (p->next->ants = 1)) : 0;
			printf("Rooms connected to start: %s, num ant: %d.\n", p->name, p->ants);
			p = p->next;
		}
	}


	/* while(p )
	{

		printf("Rooms connected to start: %s , dist to end: %d, num ant: %d.\n", p->link_room->name, lem->dist[p->link_room->room_id][lem->er->room_id], p->link_room->ants);
		p = p->next;
	} */
}

void	ant_init(t_lem	*lem)
{
	int16_t i;

	if(!(lem->tab_ants = (t_ants *)malloc(sizeof(t_ants) * lem->ant_num)))
		lem_error("ant malloc failled");
	
	i = -1;
	while(++i < lem->ant_num)
	{
		lem->tab_ants[i].ant_id = i + 1;
		lem->tab_ants[i].ant_room = lem->sr;
	}
}

int8_t path_decision(t_lem *lem, int16_t i)
{
	int16_t sum_lcm;
	int16_t j;
	t_path *p;	
	
	j = i;
	sum_lcm = 1;
	p = lem->sr->path;	
	while(i--)
	{
		sum_lcm = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], sum_lcm);
		p = p->next;
	}
	sum_lcm = sum_lcm / j;
	return(sum_lcm);
}

void move_ants(t_lem	*lem)
{
	int16_t i;
	int16_t sum_lcm;
	i = 0;
	
	t_path *p;
	p = lem->sr->path;
	while(p)
	{
		i++;
		p = p->next;
	}
	
	while(path_decision(lem , i) > lem->ant_num)
		i--;
	
	lem->rem_ants = 0;
	
	while(lem->rem_ants < lem->ant_num)
	{

	}
}