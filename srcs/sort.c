/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:20:51 by nwang             #+#    #+#             */
/*   Updated: 2018/06/02 18:46:10 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path			*merge_sorted_halves(t_path *a, t_path *b, t_lem *lem)
{
	t_path		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (lem->dist[a->link_room->room_id][lem->er->room_id]
		<= lem->dist[b->link_room->room_id][lem->er->room_id])
	{
		result = a;
		result->next = merge_sorted_halves(a->next, b, lem);
	}
	else
	{
		result = b;
		result->next = merge_sorted_halves(a, b->next, lem);
	}
	return (result);
}

void			bisect_list(t_path *source, t_path **front, t_path **back)
{
	t_path		*fast;
	t_path		*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

void			sort_path(t_path **tmp, t_lem *lem)
{
	t_path		*head;
	t_path		*a;
	t_path		*b;

	head = tmp;
	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	bisect_list(head, &a, &b);
	sort_path(&a, lem);
	sort_path(&b, lem);
	*tmp = merge_sorted_halves(a, b, lem);
}
