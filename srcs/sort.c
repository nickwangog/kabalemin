/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:20:51 by nwang             #+#    #+#             */
/*   Updated: 2018/05/31 19:20:53 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
 
t_path* merge_sorted_halves(t_path *a, t_path *b, t_lem *lem)
{
    t_path* result = NULL;
 
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    if (lem->dist[a->link_room->room_id][lem->er->room_id] <= lem->dist[b->link_room->room_id][lem->er->room_id])
    {
        result = a;
        result->next = merge_sorted_halves(a->next, b, lem);
    }
    else
    {
        result = b;
        result->next = merge_sorted_halves(a, b->next, lem);
    }
    return(result);
    }
 
void bisect_linkedlist(t_path *source, t_path** front_half, t_path** back_half)
{
    t_path* fast;
    t_path* slow;

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
    *front_half = source;
    *back_half = slow->next;
    slow->next = NULL;
}

void sort_path(t_path **tmp, t_lem *lem)
{
    t_path *head = *tmp;
    t_path *a;
    t_path *b;
 
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    } 
    bisect_linkedlist(head, &a, &b); 
    sort_path(&a, lem);
    sort_path(&b, lem);
    *tmp = merge_sorted_halves(a, b, lem);
}