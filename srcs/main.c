/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:32:22 by nwang             #+#    #+#             */
/*   Updated: 2018/05/29 18:25:53 by lkaba            ###   ########.fr       */
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
	if(is_valid_start_end(&lem))
		lem_error("no valid path between start and end rooms");

	//check if end room is INF, no valid solution
	//valid path from start to end && no rooms without links
	print_map(&lem);
	// print_solution(&lem);
	ft_printf("%d\n", lem.ant_num);
	ft_printf("%d\n", lem.num_room);
	ft_printf("%d\n", lem.sr->num_links);
	ft_printf("%d\n", lem.er->num_links);
	// ft_printf("%d\n", lem.start);
	// ft_printf("%d\n", lem.end);
	return (0);
}
