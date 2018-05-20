/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:32:22 by nwang             #+#    #+#             */
/*   Updated: 2018/05/02 00:31:41 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{	
	t_lem	*lem;

	(void)argv;
	if (argc > 1)
		ft_printf("usage: ./lem-in < (map)\n");
	lem = (t_lem *)ft_memalloc(sizeof(t_lem));
	read_lemin(lem);
	ft_printf("%d\n", lem->ant_num);
	return (0);
}
