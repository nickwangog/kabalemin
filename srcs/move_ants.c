/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:17:17 by nwang             #+#    #+#             */
/*   Updated: 2018/06/01 20:19:08 by lkaba            ###   ########.fr       */
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

void path_decision(t_lem *lem)
{
	int16_t temp;
	int16_t j;
	temp = 1;
	t_path *p;	
	
	p = lem->sr->path;
	j = lem->count;		
	while(j--)
	{
		temp = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], temp);
		p = p->next;
	}
	lem->sum_lcm = temp;
}

// int16_t sum_ant(t_lem *lem)
// {
// 	int16_t sum_lcm;

// 	sum_lcm = 0;
// 	if(sum_lcm > lem->ant_num)
// 	{
// 		sum_lcm = path_decision(lem);
// 	}
// 	return(sum_lcm);
	
}

void	best_lcm(t_lem *lem)
{
	while (lem->sum_lcm > lem->ant_num)
	{
		lem->count--;
		path_decision(lem);
	}
}

void move_ants(t_lem	*lem)
{
	int16_t i;
	int16_t temp;
	t_path	*p;	
	
	i = 0;
	p = lem->sr->path;	
	count_sr_conn(lem);
	path_decision(lem);
	ant_loop(lem);
	
	lem->rem_ants = 0;
		else
			move ants to the number of paths count
			subtract from ant total
			track and store ant movements to print
	
	while(lem->rem_ants < lem->ant_num)
	{

	}
}