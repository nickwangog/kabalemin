/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:32:22 by nwang             #+#    #+#             */
/*   Updated: 2018/05/21 17:32:01 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{	
	t_lem	lem;
	
	ft_bzero(&lem, sizeof(t_lem));
	(void)argv;
	if (argc > 1)
		ft_printf("usage: ./lem-in < (map)\n");
	read_lemin(&lem);
	ft_printf("%d\n", lem.ant_num);
	return (0);
}
