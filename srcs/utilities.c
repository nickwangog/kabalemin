/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:26:35 by nwang             #+#    #+#             */
/*   Updated: 2018/05/22 19:41:26 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	lem_error(int8_t n)
{
	if (n == 1)
		ft_putstr("Error : invalid ants.\n");
	if (n == 2)
		ft_putstr("Error : invalid rooms.\n");
	if (n == 3)
		ft_putstr("Error : invalid links.\n");
	if (n == 4)
		ft_putstr("Error : invalid start or end\n");
	if (n == 5)
		ft_putstr("Error : malloc error\n");
	exit(1);
}

int		countspace(char *s)
{
	int space;
	int	i;

	i = 0;
	space = 0;
	while(s[i])
	{
		if (s[i] == ' ')
			space++;
		i++;
	}
	return (space);
}