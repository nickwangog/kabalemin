/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:17:17 by nwang             #+#    #+#             */
/*   Updated: 2018/06/03 10:04:02 by lkaba            ###   ########.fr       */
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


int16_t		path_decision(t_lem *lem)
{
	int16_t temp;
	int16_t j;
	temp = 1;
	t_path *p;	
	
	p = lem->sr->path;
	lem->count = lem->sr->num_links;
	printf("links =n%d\n", lem->sr->num_links);
	j = lem->count;		
	while(j--)
	{
		temp = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], temp);
		p = p->next;
	}
	return(temp);
}

void	best_lcm(t_lem *lem)
{
	lem->sum_lcm = path_decision(lem);
	while (lem->sum_lcm > lem->ant_num)
	{
		lem->count--;
		lem->sum_lcm = path_decision(lem);
	}
	printf("lem->count value = %d | lcm =  %d\n", lem->count, lem->sum_lcm);
}

void	move_ant(t_lem *lem, t_ants *a, t_rooms *r)
{
	//if(a->ant_room != lem->sr)
		a->ant_room->has_ant = 0;
	a->ant_room = r;
	a->ant_room->has_ant = 1;
	lem->board_ants -= r == lem->er ? 1 : 0;
	ft_printf("L%d-%s ",a->ant_id + 1, a->ant_room->name);
	//print the space;
}

/* check_start_paths(t_lem *lem);
{

} */

void move_ant_start(t_lem *lem, t_ants *a)
{
	printf("im here\n");
	if (lem->sum_lcm <= lem->ant_num)
	{
		if(lem->j < lem->count)
		{
			if (lem->j == lem->count - 1)
			{
				lem->j = 0;
				lem->p = lem->sr->path;
			}
			if(lem->p->link_room->has_ant == 0)
			{
				move_ant(lem, a, lem->p->link_room);
				//lem->p->link_room->has_ant = 1;
				lem->start_ants--;
				lem->j++;
			}
			else
			{
				lem->p = lem->p->next;
				printf("rom_name = %s\n", lem->p->link_room->name);
				move_ant(lem, a, lem->p->link_room);
				//lem->p->link_room->has_ant = 1;
				lem->start_ants--;
				lem->j++;
			}
			
		}
	}
	if(lem->sum_lcm >= lem->ant_num && lem->count != 1)
		best_lcm(lem);
}

void lem_ants(t_lem	*lem)
{
	int16_t i;
	int16_t j;
	int16_t dist1;
	int16_t dist2;
	//int16_t temp;
	t_ants ants[lem->ant_num];
	
	j = -1;
	ant_init(ants, lem->ant_num, lem->sr);
	lem->sum_lcm = path_decision(lem);
	lem->board_ants = lem->ant_num;
	lem->start_ants = lem->ant_num;
	lem->p = lem->sr->path;
	// check_start_paths(lem);
	while (lem->board_ants)
	{
		// printf("board_ants = %d\n",lem->board_ants);
		i = -1;
		while (++i < lem->ant_num)
		{
			if (ants[i].ant_room == lem->sr)
			{
				printf("------------->i = %d", i);
				move_ant_start(lem, &ants[i]);
				//continue;
			}
			else if (ants[i].ant_room == lem->er)
				continue ;
			else if (ants[i].ant_room->path->link_room == lem->er)
				move_ant(lem, &ants[i], lem->er);
			else if (/* (ants[i].ant_room != lem->sr) && ( */ants[i].ant_room->path->link_room->has_ant == 0)
				move_ant(lem, &ants[i], ants[i].ant_room->path->link_room);
			else
			{
				lem->p = ants[i].ant_room->path->next;
				while(lem->p)
				{
					dist1 = lem->dist[lem->p->link_room->room_id][lem->er->room_id]; 
					dist2 = lem->dist[ants[i].ant_room->room_id][lem->er->room_id];
					if (lem->p->link_room->has_ant == 0)
						if(dist1 < dist2 && lem->board_ants < dist1)
							move_ant(lem, &ants[i], lem->p->link_room);
					lem->p = lem->p->next;
				}
			}
		}
		ft_putstr("\n");
	}
}
