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

void			ant_init(t_lem *lem, t_ants *ants, int16_t n, t_rooms *sr)
{
	int16_t		i;

	i = -1;
	lem->start_ants = lem->ant_num;
	lem->board_ants = lem->ant_num;
	lem->p = lem->sr->path;
	lem->p_to_take = lem->sr->num_links;
	lem->k = NULL;
	while (++i < n)
	{
		ants[i].ant_id = i;
		ants[i].ant_room = sr;
	}
	best_lcm(lem);
}

void			move_ant(t_lem *lem, t_ants *a, t_rooms *r)
{
	if (a->ant_room == lem->sr)
		lem->start_ants--;
	a->ant_room->has_ant = 0;
	a->ant_room = r;
	a->ant_room->has_ant = 1;
	lem->board_ants -= r == lem->er ? 1 : 0;
	if (lem->space)
		ft_putchar(' ');
	lem->space = 1;
	if (lem->color)
		ft_printf(C_CYN "L" C_GRN "%d" C_RED "-" C_YEL "%s",
			a->ant_id + 1, a->ant_room->name);
	else
		ft_printf("L%d-%s", a->ant_id + 1, a->ant_room->name);
}

void			move_antcheck(t_lem *lem, t_ants *a, t_rooms *r)
{
	t_rooms *p;

	p = r;
	if (lem->j < lem->p_to_take)
	{
		if (p->has_ant == 0)
		{
			move_ant(lem, a, p);
			lem->j++;
		}
		else if (lem->j < lem->p_to_take)
		{
			if (p->path->next)
			{
				p->path = p->path->next;
				if (p->has_ant == 0)
					move_ant(lem, a, p);
				lem->j++;
			}
		}
	}
}

void			ant_loop(t_lem *lem, t_ants *ants, int16_t d1, int16_t d2)
{
	lem->k = ants->ant_room->path;
	while (lem->k && lem->j < lem->p_to_take)
	{
		d1 = lem->dist[lem->k->link_room->room_id][lem->er->room_id];
		d2 = lem->dist[ants->ant_room->room_id][lem->er->room_id];
		if (lem->k->link_room->has_ant == 0)
			if (d1 <= d2)
			{
				move_antcheck(lem, ants, lem->k->link_room);
				break ;
			}
		lem->k = lem->k->next;
	}
}

void			lem_ants(t_lem *lem, int16_t i)
{
	t_ants		ants[lem->ant_num];

	ant_init(lem, ants, lem->ant_num, lem->sr);
	while (lem->board_ants && (i = -1))
	{
		lem->space = 0;
		while (++i < lem->ant_num)
		{
			if (lem->sum_lcm >= lem->start_ants)
			{
				best_lcm(lem);
				lem->p_to_take > 1 ? lem->p_to_take-- : 0;
			}
			if (ants[i].ant_room->path->link_room == lem->er)
				move_ant(lem, &ants[i], ants[i].ant_room->path->link_room);
			else if (ants[i].ant_room == lem->er)
				continue;
			else if (ants[i].ant_room->path->link_room->has_ant == 0)
				move_antcheck(lem, &ants[i], ants[i].ant_room->path->link_room);
			else
				ant_loop(lem, &ants[i], 0, 0);
			lem->j >= lem->p_to_take ? lem->j = 0 : 0;
		}
		ft_putstr("\n");
	}
}
