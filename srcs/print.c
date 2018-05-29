/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:23:57 by nwang             #+#    #+#             */
/*   Updated: 2018/05/28 23:23:58 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    print_map(t_lem *lem)
{
    // int fd;

    // fd = 0;
    // fd = open(input, O_RDONLY);
    ft_putnbr(lem->ant_num);
    while (get_next_line(3, &lem->line) > 0)
    {
        ft_putstr(lem->line);
    }
    ft_strdel(&lem->line);
    //need to print map, either print as we read or store the map and print
    //only if valid??
}

// void    print_solution(t_lem *lem)
// {

// }