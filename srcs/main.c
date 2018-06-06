/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:32:22 by nwang             #+#    #+#             */
/*   Updated: 2018/06/05 06:55:43 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_lem	lem;
	
	ft_bzero(&lem, sizeof(t_lem));
	(void)argv;
	if (argc > 1)
		lem_error("usage: ./lem-in < (map)");
	read_lemin(&lem);
	dijk_init(&lem);
	if (is_valid_start_end(&lem))
		lem_error("no valid path between start and end rooms");
	check_endroom(&lem);
	lem_ants(&lem);
	//ft_putstr(lem.buf);
	return (0);
}
