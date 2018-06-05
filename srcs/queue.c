#include "lemin.h"

//Queue Init

t_queue *init(t_queue *q)
{
	q = (t_queue *)malloc(sizeof(t_queue));
	q->front = NULL;
	q->front = NULL;
}

//enqueue
void enqueue(t_queue *q, t_rooms *r)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->next = NULL;
	tmp->data = n;
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
void	*dequeue(t_queue *q)
{
	t_node *tmp;
	void *tp_data;

	tmp = q->front;
	if(is_empty(q))
		return(NULL);
	if(q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
		q->front = q->front->next;
	tp_data = tmp->data;
	free(tmp);
	return (tp_data);
}

//front
void	*front(t_queue *q)
{
	return(q->front->data);
}

//is_empty

int is_empty(t_queue *q)
{
	return(q->rear == NULL);
}
