/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:49:29 by lkaba             #+#    #+#             */
/*   Updated: 2018/06/05 17:37:26 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		enqueue(t_queue *q, t_rooms *r)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		lem_error("Malloc fail");
	tmp->r = r;
	tmp->next = NULL;
	if (is_empty(q))
	{
		q->rear = tmp;
		q->front = tmp;
		return ;
	}
	q->rear->next = tmp;
	q->rear = tmp;
}

t_rooms		*dequeue(t_queue *q)
{
	t_node	*tmp;
	t_rooms	*tp_data;

	if (is_empty(q))
		return (NULL);
	tmp = q->front;
	tp_data = q->front->r;
	if (q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
		q->front = q->front->next;
	free(tmp);
	return (tp_data);
}

void		*front(t_queue *q)
{
	return (q->front->r);
}

int			is_empty(t_queue *q)
{
	return (q->front == NULL);
}

void		bfs(t_lem *lem, t_rooms *r, int16_t i)
{
	t_queue	q;
	t_path	*t;
	int16_t	v[lem->num_room];

	ft_bzero((t_queue *)&q, sizeof(t_queue));
	while (++i < lem->num_room)
		v[i] = 0;
	v[r->room_id] = 1;
	v[lem->sr->room_id] = 1;
	enqueue(&q, r);
	while (!(is_empty(&q)))
	{
		r = dequeue(&q);
		t = r->path;
		while (t)
		{
			if (v[t->link_room->room_id] == 0)
			{
				v[t->link_room->room_id] = 1;
				enqueue(&q, t->link_room);
			}
			t = t->next;
		}
	}
	v[lem->er->room_id] == 0 ? r->has_ant = 1 : 0;
}
