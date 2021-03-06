/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:56:25 by nwang             #+#    #+#             */
/*   Updated: 2018/05/29 19:27:44 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	cleartab(t_lem *lem)
{
	ft_memdel((void**)&lem->tab[0]);
	ft_memdel((void**)&lem->tab[1]);
	ft_memdel((void**)&lem->tab[2]);
	free(lem->tab);
}

void	create_room(t_lem *lem, t_rooms *temp, t_rooms *temp1)
{
	if (!(temp = (t_rooms *)ft_memalloc(sizeof(t_rooms))))
		lem_error("failed to malloc size of t_rooms");
	temp->next = lem->head;
	temp->name = ft_strdup(lem->tab[0]);
	lem->sr = !lem->sr && lem->start == 1 ? temp : lem->sr;
	lem->er = !lem->er && lem->end == 1 ? temp : lem->er;
	ft_linedigit(lem->tab[1]) ? temp->x =
		ft_atoi(lem->tab[1]) : lem_error("invalid room coordinates");
	ft_linedigit(lem->tab[2]) ? temp->y =
		ft_atoi(lem->tab[2]) : lem_error("invalid rooms coordinates");
	cleartab(lem);
	temp1 = lem->head;
	while (temp1)
	{
		if (!ft_strcmp(temp1->name, temp->name))
			lem_error("duplicate room name");
		if ((temp1->x == temp->x) && (temp1->y == temp->y))
			lem_error("same room coordinate");
		temp1 = temp1->next;
	}
	lem->head = temp;
	lem->num_room++;
	lem->head->room_id = lem->num_room - 1;
}
