/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:26:35 by nwang             #+#    #+#             */
/*   Updated: 2018/06/01 19:28:14 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	lem_error(char *s)
{
	ft_printf("Error: %s.\n", s);
	exit(1);
}

int		countspace(char *s)
{
	int space;
	int	i;

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

int		is_valid_start_end(t_lem *lem)
{
	if(lem->dist[lem->sr->room_id][lem->er->room_id] == INF)
		return (1);
	return (0);	
}

unsigned int  hcf(unsigned int a, unsigned int b)
{
	if(b == 0)
		return(a);
	return(hcf(b, (a%b)));
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	return((a * b) / hcf(a,b));
}

void		count_sr_conn(t_lem *lem)
{
	t_path *p;	
	
	
	p = lem->sr->path;		
	while(p)
	{
		lem->count++;
		p = p->next;
	}
}

// int is_empty(t_queue *q)
// {
// 	return(q->rear == NULL);
// }

// t_queue *init(t_queue *q)
// {
// 	q = (t_queue *)malloc(sizeof(t_queue));
// 	q->front = NULL;
// 	q->front = NULL;
// }