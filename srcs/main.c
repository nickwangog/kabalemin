/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:32:22 by nwang             #+#    #+#             */
/*   Updated: 2018/05/22 21:11:51 by lkaba            ###   ########.fr       */
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
	//check if end room is INF, no valid solution
	//valid path from start to end && no rooms without links
	ft_printf("%d\n", lem.ant_num);
	ft_printf("%d\n", lem.num_room);
	ft_printf("%d\n", lem.start);
	ft_printf("%d\n", lem.end);
	return (0);
}
