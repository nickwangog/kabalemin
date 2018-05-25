/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 00:31:54 by nwang             #+#    #+#             */
/*   Updated: 2018/05/23 23:45:27 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		read_ants(t_lem *lem)
{
	while (get_next_line(0, &lem->line) > 0)
	{
		if (!ft_strcmp(lem->line, "##end") || !ft_strcmp(lem->line, "##start"))
			lem_error("invalid start room or end room");
		if (lem->line[0] == '#')
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
				if (lem->ant_num < 1)
					lem_error("invalid ants");
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
	if (lem->line[0] < 33 || lem->line[0] == 'L')
		lem_error("invalid rooms");
	else if (ft_countwords(lem->line, ' ') == 3 && countspace(lem->line) == 2)
	{
		if (lem->links == 1)
			lem_error("invalid links");
		lem->tab = ft_strsplit(lem->line, ' ');
		parse_room(lem);
		return (1);
	}
	else if (ft_strchr(lem->line, '-') && ft_countwords(lem->line, ' ') == 1
		&& countspace(lem->line) == 0)
	{
		if (lem->sr_name == NULL || lem->er_name == NULL)
			lem_error("invalid start room or end room");
		//check_link(lem);
		lem->links = 1;
		return (1);
	}
	return (0);
}

void		read_rooms(t_lem *lem)
{
	while (get_next_line(0, &lem->line) > 0)
	{
		// ft_putstr(lem->line);
		// ft_putstr("\n");
		if (!ft_strcmp(lem->line, "##start") || !ft_strcmp(lem->line, "##end"))
		{
			lem->start += !ft_strcmp(lem->line, "##start") ? 1 : 0;
			lem->end += !ft_strcmp(lem->line, "##end") ? 1 : 0;
			lem->start == 1 && lem->end == 1 && !lem->sr_name &&
				!lem->er_name ? lem_error("invalid start room or end room") : 0;
			ft_strdel(&lem->line);
			if (lem->start > 1 || lem->end > 1)
				lem_error("invalid start room or end room");
		}
		else if (lem->line[0] == '#')
			ft_strdel(&lem->line);
		else if (line_validation(lem))
			ft_strdel(&lem->line);
		else
		{
			ft_strdel(&lem->line);
			lem_error("invalid rooms");
		}
	}
}

void		read_lemin(t_lem *lem)
{
	read_ants(lem);
	if (!lem->ant_num)
		lem_error("invalid ants");
	read_rooms(lem);
	if (lem->start != 1 || lem->end != 1)
		lem_error("invalid start room or end room");
	// if missing links, no valid path
	// 	error
}
