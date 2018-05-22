/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 00:31:54 by nwang             #+#    #+#             */
/*   Updated: 2018/05/21 18:49:20 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void read_ants(t_lem *lem)
{
	while(get_next_line(0, &lem->line) > 0)
	{
		if(!ft_strcmp(lem->line, "##end") || !ft_strcmp(lem->line, "##start"))
			lem_error(4);
		if(lem->line)
		{
			if(ft_isdigit(lem->line[0]) && ft_linedigit(lem->line))
			{
				lem->ant_num = ft_atoi(lem->line);
				free(lem->line);
				if(lem->ant_num < 1)
					lem_error(1);
				break ;
			}
			else
				free(lem->line);
		}
		else
			lem_error(1);
	}
}

void        read_rooms(t_lem *lem)
{
// }

// void        read_rooms(char *s, t_lem *lem)
// {
// }

void		read_lemin(t_lem *lem)
{

	read_ants(lem);
	if(!lem->ant_num)
		lem_error(1);
	
	//     ERROR1("no ants");

	// while (get_next_line(0, &line) > 0)
	// {
	//     if (!ft_strcmp(line, "##start"))
	//         mark as start room
	//     if (!ft_strcmp(line, "##end"))
	//         mark as end room
	//     if (line[0] == '#')
	//         read_rooms(line, lem);
	//         read_links(line, lem);
	// }
}
