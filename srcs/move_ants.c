/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:17:17 by nwang             #+#    #+#             */
/*   Updated: 2018/06/04 18:27:39 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ant_init(t_lem *lem, t_ants *ants, int16_t n, t_rooms *sr)
{
	int16_t i;

	i = -1;
	lem->start_ants = lem->ant_num;
	lem->board_ants = lem->ant_num;
	lem->p = lem->sr->path;
	lem->p_to_take = lem->sr->num_links;
	lem->k = NULL;
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
	j = lem->count;
	while(j--)
	{
		if(p->link_room->has_ant == 0)
			temp = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], temp);
		p = p->next;
	}
	return(temp);
}

void	best_lcm(t_lem *lem)
{
	lem->count = lem->sr->num_links;
	lem->sum_lcm = path_decision(lem);
	lem->sum_lcm /= lem->count;
	while ((lem->sum_lcm > lem->start_ants) && lem->sum_lcm > 1)
	{
		lem->count--;
		lem->sum_lcm = path_decision(lem);
		lem->sum_lcm /= lem->count;
	}
}

void	move_ant(t_lem *lem, t_ants *a, t_rooms *r)
{
	if(a->ant_room == lem->sr)
		lem->start_ants--;
	a->ant_room->has_ant = 0;
	a->ant_room = r;
	a->ant_room->has_ant = 1;
	lem->board_ants -= r == lem->er ? 1 : 0;
	ft_printf("L%d-%s ",a->ant_id + 1, a->ant_room->name);
}

void	move_antcheck(t_lem *lem, t_ants *a)
{
	if(lem->j <= lem->p_to_take)
	{
		if(lem->p->link_room->has_ant == 0)
		{
			move_ant(lem, a, lem->p->link_room);
			lem->j++;
		}
		else if(lem->j < lem->p_to_take)
		{
			if(lem->p->next)
			{
				lem->p = lem->p->next;
				if(lem->p->link_room->has_ant == 0)
					move_ant(lem, a, lem->p->link_room);
				lem->j++;
			}
		}
	}
}

void lem_ants(t_lem	*lem)
{
	int16_t i;
	t_ants ants[lem->ant_num];
	int16_t dist1;
	int16_t dist2;
	
	ant_init(lem, ants, lem->ant_num, lem->sr);
	while (lem->board_ants)
	{
		i = -1;
		while (++i < lem->ant_num)
		{
			if(i == 0 && lem->start_ants <= 2)
			{
				printf("start: %d | count: %d | sumlcm: %d | j: %d", lem->start_ants, lem->count, lem->sum_lcm, lem->j);
				exit(1);
			}
			if (lem->sum_lcm > lem->start_ants)
			{
				best_lcm(lem);
				lem->p_to_take--;
			}
			if (ants[i].ant_room->path->link_room == lem->er)
				move_ant(lem, &ants[i], ants[i].ant_room->path->link_room);
			else if (ants[i].ant_room == lem->er)
				continue;
			else if (ants[i].ant_room->path->link_room->has_ant == 0)
				move_antcheck(lem, &ants[i]);
			else
			{
				lem->k = ants[i].ant_room->path->next;
				while(lem->k)
				{
					dist1 = lem->dist[lem->p->link_room->room_id][lem->er->room_id]; 
					dist2 = lem->dist[ants[i].ant_room->room_id][lem->er->room_id];
					if (lem->k->link_room->has_ant == 0)
						if(dist1 < dist2 && lem->board_ants < dist1)
							move_antcheck(lem, &ants[i]);
					lem->k = lem->k->next;
				}
			}
			if(lem->j == lem->p_to_take)
			{
				lem->j = 0;
				lem->p = lem->sr->path;
			}
		}
		ft_putstr("\n");
	}
}