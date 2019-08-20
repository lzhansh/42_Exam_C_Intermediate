/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:55:51 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/19 17:36:48 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct s_node {
		void *content;
		struct s_node *next;
	};

	struct s_queue {
		struct s_node *first;
		struct s_node *last;
	};

struct s_queue *init(void)
{
	struct s_queue *new;

	new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	else
		queue->last->next = new;
	queue->last = new;
}

void *dequeue(struct s_queue *queue)
{
	struct s_node *first;
	void *tmp;

	if (!queue->first)
		return (NULL);
	first = queue->first;
	tmp = first->content;
	queue->first = first->next;
	queue->last = (queue->first == queue->last) ? NULL : queue->last;
	free(first);
	return (tmp);
}

void *peek(struct s_queue *queue)
{
	if (!queue->first)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue->first)
		return (1);
	return (0);
}

//int main()
//{
//	struct s_queue *new = init();
//	printf("Isempty? %d\n", isEmpty(new));
//	enqueue(new, "hey");
//	printf("Isempty? %d\n", isEmpty(new));
//	printf("1st element: %s\n", peek(new));
//	enqueue(new, "there");
//	printf("1st deq: %s\n", dequeue(new));
//	printf("Isempty? %d\n", isEmpty(new));
//	printf("1st element: %s\n", peek(new));
//	printf("2nd deq: %s\n", dequeue(new));
//	printf("Isempty? %d\n", isEmpty(new));
//	printf("1st element: %s\n", peek(new));
//	return (0);
//}
