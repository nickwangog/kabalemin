/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 00:31:54 by nwang             #+#    #+#             */
/*   Updated: 2018/05/02 00:33:41 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void        read_ants(t_lem *lem)
{
    char *line;
    int i;

    i = 0;
    line = NULL;
    if (get_next_line(0, &line) > 0)
    {   
        while (line[0] == '#')
		{
			ft_memdel((void **)&line);
			if (get_next_line(0, &line) == -1)
			{
				line = NULL;
				break ;
			}
        }
        while(line[i])
        {
            if (!ft_isdigit(line[i]) || line == NULL)
            {
                line = NULL;
                ft_printf("Error, no ants.\n");
                exit (0);
            }
            i++;
        }
    }
    lem->ant_num = (line != NULL && *line != '\0') ? ft_atoi(line) : 0;
    ft_memdel((void **)&line);
}

// void        read_rooms(char *s, t_lem *lem)
// {
// }

// void        read_rooms(char *s, t_lem *lem)
// {
// }

void		read_lemin(t_lem *lem)
{
    char *line;

    line = NULL;
    read_ants(lem);
    while (get_next_line(0, &line) > 0)
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
