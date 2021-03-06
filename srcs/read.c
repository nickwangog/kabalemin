/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 00:31:54 by nwang             #+#    #+#             */
/*   Updated: 2018/06/03 15:49:42 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		read_ants(t_lem *lem)
{
	while (get_next_line(0, &lem->line) > 0)
	{
		if (!ft_strcmp(lem->line, "##end") || !ft_strcmp(lem->line, "##start"))
			lem_error("invalid start room or end room");
		if (lem->line && lem->line[0] == '#')
		{
			ft_strdel(&lem->line);
			continue ;
		}
		if (lem->line)
		{
			if (ft_isdigit(lem->line[0]) && ft_linedigit(lem->line))
			{
				lem->ant_num = ft_atoi(lem->line);
				ft_strdel(&lem->line);
				if (lem->ant_num < 1 || lem->ant_num > 32767)
					lem_error("invalid ants (1-32767)");
				break ;
			}
			ft_strdel(&lem->line);
			lem_error("invalid ants");
		}
		lem_error("invalid ants");
	}
}

int			line_validation(t_lem *lem)
{
	t_rooms *temp;
	t_rooms *temp1;

	temp = NULL;
	temp1 = NULL;
	if (lem->line[0] < 33 || lem->line[0] == 'L')
		lem_error("invalid rooms");
	else if (ft_countwords(lem->line, ' ') == 3 && countspace(lem->line) == 2)
	{
		if (lem->links == 1)
			lem_error("invalid links");
		lem->tab = ft_strsplit(lem->line, ' ');
		create_room(lem, temp, temp1);
		return (1);
	}
	else if (ft_strchr(lem->line, '-') && ft_countwords(lem->line, ' ') == 1
		&& countspace(lem->line) == 0)
	{
		if (lem->sr == NULL || lem->er == NULL)
			lem_error("invalid start room or end room");
		create_link(lem);
		lem->links = 1;
		return (1);
	}
	return (0);
}

void		room_error(t_lem *lem)
{
	ft_strdel(&lem->line);
}

void		read_rooms(t_lem *lem)
{
	while (get_next_line(0, &lem->line) > 0)
	{
		ft_strcat(lem->buf, lem->line);
		ft_strcat(lem->buf, "\n");
		if (!ft_strcmp(lem->line, "##start") || !ft_strcmp(lem->line, "##end"))
		{
			lem->start += !ft_strcmp(lem->line, "##start") ? 1 : 0;
			lem->end += !ft_strcmp(lem->line, "##end") ? 1 : 0;
			lem->start == 1 && lem->end == 1 && !lem->sr &&
				!lem->er ? lem_error("invalid start room or end room") : 0;
			ft_strdel(&lem->line);
			if (lem->start > 1 || lem->end > 1)
				lem_error("invalid start room or end room");
		}
		else if (lem->line[0] == '#')
			ft_strdel(&lem->line);
		else if (line_validation(lem))
			ft_strdel(&lem->line);
		else
			room_error(lem);
	}
}

void		read_lemin(t_lem *lem)
{
	char room_name[50];

	read_ants(lem);
	if (!lem->ant_num)
		lem_error("invalid ants");
	read_rooms(lem);
	if (lem->start != 1 || lem->end != 1)
		lem_error("invalid start room or end room");
	if (!lem->links)
		lem_error("no existing links");
	if (is_no_rlinks(lem->head, room_name))
	{
		ft_printf("Error: the room %s has no link.\n", room_name);
		exit(1);
	}
}
