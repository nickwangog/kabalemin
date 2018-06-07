/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_lcm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:04:31 by nwang             #+#    #+#             */
/*   Updated: 2018/06/06 17:04:32 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int16_t			path_decision(t_lem *lem)
{
	int16_t		temp;
	int16_t		j;
	t_path		*p;

	temp = 1;
	p = lem->sr->path;
	j = lem->count;
	while (j--)
	{
		temp = lcm(lem->dist[p->link_room->room_id][lem->er->room_id], temp);
		p = p->next;
	}
	return (temp);
}

void			best_lcm(t_lem *lem)
{
	t_path		*p;

	lem->count = lem->sr->num_links;
	p = lem->sr->path;
	while (p)
	{
		if (p->link_room->has_ant == 1)
			lem->count--;
		p = p->next;
	}
	lem->sum_lcm = path_decision(lem);
	if (lem->count != 0)
		lem->sum_lcm /= lem->count;
	while (lem->sum_lcm > lem->start_ants && lem->count > 1)
	{
		lem->count--;
		lem->sum_lcm = path_decision(lem);
		if (lem->count != 0)
			lem->sum_lcm /= lem->count;
	}
}
