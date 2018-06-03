/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:26:35 by nwang             #+#    #+#             */
/*   Updated: 2018/06/02 18:50:49 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			lem_error(char *s)
{
	ft_printf("Error: %s.\n", s);
	exit(1);
}

int				countspace(char *s)
{
	int			space;
	int			i;

	i = 0;
	space = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			space++;
		i++;
	}
	return (space);
}

int				is_valid_start_end(t_lem *lem)
{
	if (lem->dist[lem->sr->room_id][lem->er->room_id] == INF)
		return (1);
	return (0);
}

unsigned int	hcf(unsigned int a, unsigned int b)
{
	if (b == 0)
		return (a);
	return (hcf(b, (a % b)));
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	return ((a * b) / hcf(a, b));
}
