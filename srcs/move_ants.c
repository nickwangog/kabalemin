/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:17:17 by nwang             #+#    #+#             */
/*   Updated: 2018/06/02 19:58:29 by lkaba            ###   ########.fr       */
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

void	move_ant(t_lem *lem, t_ants *a, t_rooms *r)
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

void lem_ants(t_lem	*lem)
{
	int16_t i;
	int16_t j;
	//int16_t temp;
	t_path	*p;	
	t_ants ants[lem->ant_num];
	
	j = -1;
	ant_init(ants, lem->ant_num, lem->sr);
	path_decision(lem);
	lem->board_ants = lem->ant_num;
	lem->start_ants = lem->ant_num;
		
	p = lem->sr->path;
	while (lem->board_ants)
	{
			i = -1;
			while (++i < lem->ant_num)
			{
				if (ants[i].ant_room == lem->er)
					continue ;
				if (ants[i].ant_room->path->link_room == lem->er)
					move_ant(lem, &ants[i], lem->er);
				else if (ants[i].ant_room == lem->sr)
				{
					if (lem->sum_lcm < lem->ant_num)
					{
						if (++j < lem->count)
						{
							if (ants[i].ant_room->path->link_room->has_ant == 0)
							{
								move_ant(lem, &ants[i], p->link_room);
								lem->start_ants--;
							}
							p = p->next;
						}
						printf("value of j = %d\n", j);
						if (j == lem->count)
						{
							j = -1;
							p = lem->sr->path;
						}
					}
					else
						best_lcm(lem);
				}
				else if (ants[i].ant_room->path->link_room->has_ant == 0)
					move_ant(lem, &ants[i], ants[i].ant_room->path->link_room);
		}
	}
}