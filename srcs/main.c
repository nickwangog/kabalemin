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
	if (argc > 2)
		lem_error("usage: ./lem-in < (map) (-g)");
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-g"))
			lem_error("usage: ./lem-in < (map) (-g)");
		else if (!ft_strcmp(argv[1], "-g"))
			lem.color = 1;
	}
	read_lemin(&lem);
	dijk_init(&lem);
	if (is_valid_start_end(&lem))
		lem_error("no valid path between start and end rooms");
	check_endroom(&lem);
	if (lem.color)
		ft_printf(C_MAG "%d\n%s\n" C_RESET, lem.ant_num, lem.buf);
	else
		ft_printf("%d\n%s\n", lem.ant_num, lem.buf);
	lem_ants(&lem, 0);
	return (0);
}
