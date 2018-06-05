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
	//printf("links =n%d\n", lem->sr->num_links);
	j = lem->count;
	while(j--)
	{
		temp = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], temp);
		//printf("temp = %d\n", temp);
		p = p->next;
	}

	return(temp);
}

void	best_lcm(t_lem *lem)
{
	lem->count = lem->sr->num_links;
	lem->sum_lcm = path_decision(lem);
	//exit (1);
	if(!dist_equ(lem))
		lem->sum_lcm /= lem->count;
	while ((lem->sum_lcm > lem->start_ants) && lem->sum_lcm > 1)
	{
		lem->count--;
		lem->sum_lcm = path_decision(lem);
		if(!dist_equ(lem))
			lem->sum_lcm /= lem->count;
		//printf("j = %d | start ant = %d\n", lem->sum_lcm, lem->count);
	}
	if (dist_equ(lem) && lem->sum_lcm == 1)
	{
		lem->sum_lcm = lem->sr->num_links;
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
	//print the space;
}

void move_ant_start(t_lem *lem, t_ants *a)
{	
	
	//printf("stat_ant = %d | %d | %d\n", lem->start_ants, lem->count, lem->sum_lcm);
	// if(lem->sr->num_links == 1 && !lem->sr->path->link_room->has_ant)
	// 	move_ant(lem, a, lem->sr->path->link_room);
	if(lem->sum_lcm <= lem->start_ants)
	{
				
		if(lem->j < lem->sum_lcm)
		{
			if(lem->p->link_room->has_ant == 0)
			{
				//ft_printf("Ant: %d goes from %s to %s", a->ant_id + 1, a->ant_room->name, lem->p->link_room->name);
				move_ant(lem, a, lem->p->link_room);
				lem->j++;
			}
			else if(lem->j < lem->sum_lcm && lem->sum_lcm != 1)
			{
				if(lem->p->next)
				{
					lem->p = lem->p->next;
					if(lem->p->link_room->has_ant == 0)
					{
						//ft_printf("Ant: %d goes from %s to %s, j = %d", a->ant_id + 1, a->ant_room->name, lem->p->link_room->name, lem->j);
						move_ant(lem, a, lem->p->link_room);
					}
					lem->j++;
				}
			}
		}
	}
	if (a->ant_id == 0 && lem->start_ants < 1)
	{
		ft_printf("start: %d | count: %d | sumlcm: %d | j: %d | name : %s", lem->start_ants, lem->count, lem->sum_lcm, lem->j, lem->p->link_room->name);
		exit(1);
	}
	if((lem->sum_lcm > lem->start_ants) && lem->start_ants)
		best_lcm(lem);
	//exit(1);
}

void lem_ants(t_lem	*lem)
{
	int16_t i;
	int16_t j;
	int16_t dist1;
	int16_t dist2;
	t_ants ants[lem->ant_num];
	
	j = -1;
	ant_init(ants, lem->ant_num, lem->sr);
	lem->start_ants = lem->ant_num;
	lem->board_ants = lem->ant_num;
	lem->p = lem->sr->path;
	best_lcm(lem);
	printf("stat_ant = %d | %d | %d\n", lem->start_ants, lem->count, lem->sum_lcm);
	//exit(1);
	while (lem->board_ants)
	{
		i = -1;
		while (++i < lem->ant_num)
		{
			// if(i == 6)
			// 	exit(1);
			// 	ft_printf("ant name = %s\n",ants[i].ant_room->path->link_room->name);
			if (ants[i].ant_room->path->link_room == lem->er)
			{
				// ft_putstr("kkshgohweogehgogeg");
				move_ant(lem, &ants[i], ants[i].ant_room->path->link_room);
				//continue;
			}
			else if (ants[i].ant_room == lem->sr)
			{
				// if(lem->start_ants <= 2 && i == 5)
				// {
				// 	printf("start: %d | count: %d | sumlcm: %d | j: %d | name : %s", lem->start_ants, lem->count, lem->sum_lcm, lem->j, lem->p->link_room->name);
				// 	exit(1);
				// }
				move_ant_start(lem, &ants[i]);
				
			}
			else if (ants[i].ant_room == lem->er)
				continue;
			else if (ants[i].ant_room->path->link_room->has_ant == 0)
			{
				// if (lem->start_ants <= 3 && i == 3)
				// 	ft_putstr("ningi");
				move_ant(lem, &ants[i], ants[i].ant_room->path->link_room);
			}
			else
			{
				// ft_putstr("kkshgohweogehgogeg");
				//  exit (1);
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
			if(lem->j == lem->sum_lcm)
			{
				// if (i == 4)
				// 	ft_printf("j ==== %d", lem->j);
				lem->j = 0;
				lem->p = lem->sr->path;
			}
			// if(lem->start_ants <= 3 && i == 2)
			// {
			// 	printf("start: %d | count: %d | sumlcm: %d | j: %d", lem->start_ants, lem->count, lem->sum_lcm, lem->j);
			// 	exit(1);
			// }
		}
		ft_putstr("\n");
	}
}

int		dist_equ(t_lem *lem)
{
	t_path *p;
	int dist;
	int check;

	dist = 0;
	p = lem->sr->path;
	check = lem->dist[p->link_room->room_id][lem->er->room_id];
	while(p)
	{
		dist = lem->dist[p->link_room->room_id][lem->er->room_id];
		//printf("dist = %d  check = %d\n", dist, check);
		if (check != dist)
			return(0);
		p = p->next;
	}
	return (1);
}