/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:49:29 by lkaba             #+#    #+#             */
/*   Updated: 2018/06/05 17:29:27 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//Queue Init

t_queue *init(t_queue *q)
{
	if(!(q = (t_queue *)malloc(sizeof(t_queue))))
		lem_error("Malloc fail");
	q->front = NULL;
	q->front = NULL;
	return(q);
}
//enqueue
void enqueue(t_queue *q, t_rooms *r)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		lem_error("Malloc fail");
	tmp->r = r;
	tmp->next = NULL;
	if(is_empty(q))
	{
		q->rear = tmp;
		q->front = tmp;
		return ;
	}
	q->rear->next = tmp;
	q->rear = tmp;
}
//dequeue
t_rooms	*dequeue(t_queue *q)
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
//front
void	*front(t_queue *q)
{
	return(q->front->r);
}
//is_empty
int is_empty(t_queue *q)
{
	return(q->front == NULL);
}
