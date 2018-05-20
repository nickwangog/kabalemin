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
        while(line[i])
        {
            if (!ft_isdigit(line[i]))
            {
                line = NULL;
                break ;
            }
            i++;
        }
    }
    lem->ant_num = (line != NULL && *line != '\0') ? ft_atoi(line) : 0;
}

void		read_lemin(t_lem *lem)
{
    read_ants(lem);
}
