/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:20:03 by nwang             #+#    #+#             */
/*   Updated: 2018/06/02 17:58:15 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				check_duplicate_link(t_path *iter, t_rooms *link_to_add)
{
	while (iter)
	{
		if (ft_strcmp(iter->link_room->name, link_to_add->name) == 0)
			return (0);
		iter = iter->next;
	}
	return (1);
}

int				link_validation(t_lem *lem)
{
	t_rooms		*temp;

	temp = lem->head;
	if (!ft_strcmp(lem->tab[0], lem->tab[1]))
		lem_error("room link to itself");
	while (temp)
	{
		if (!ft_strcmp(temp->name, lem->tab[0]))
			lem->a = temp;
		if (!ft_strcmp(temp->name, lem->tab[1]))
			lem->b = temp;
		if (lem->a && lem->b)
			break ;
		temp = temp->next;
	}
	if (temp)
	{
		if (!check_duplicate_link(lem->a->path, lem->b) ||
				!check_duplicate_link(lem->b->path, lem->a))
			lem_error("duplicate link in the map");
		return (1);
	}
	return (0);
}

void			create_link(t_lem *lem)
{
	lem->tab = ft_strsplit(lem->line, '-');
	if (link_validation(lem))
	{
		add_link(lem);
		lem->a = 0;
		lem->b = 0;
	}
	else
		lem_error("Incognito link name");
	free(lem->tab[0]);
	free(lem->tab[1]);
	free(lem->tab);
	lem->tab = NULL;
}

void			add_link(t_lem *lem)
{
	t_path		*new_path;
	t_path		*new_path2;

	new_path = malloc(sizeof(t_path));
	new_path2 = malloc(sizeof(t_path));
	if (!new_path || !new_path2)
		lem_error("failed to malloc lem->a size of t_path");
	new_path->link_room = lem->b;
	new_path->next = lem->a->path;
	lem->a->path = new_path;
	lem->a->num_links++;
	new_path2->link_room = lem->a;
	new_path2->next = lem->b->path;
	lem->b->path = new_path2;
	lem->b->num_links++;
}

int				is_no_rlinks(t_rooms *head, char *room_name)
{
	t_rooms *temp;

	temp = head;
	while (temp)
	{
		if (temp->num_links == 0)
		{
			ft_strcpy(room_name, temp->name);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
