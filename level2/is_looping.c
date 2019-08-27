/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:57:45 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/26 14:15:34 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct s_node {
    int value;
    struct s_node *next;
};

int is_looping(struct s_node *node)
{
	struct s_node *p1;
	struct s_node *p2;

	p1 = node;
	p2 = node;
	while (p1 && p2)
	{
		p1 = p1->next;
		p2 = p2->next;
		if (p2)
			p2 = p2->next;
		if (p1 == p2)
			return (1);
	}
	return (0);
}

//struct s_node *new_add(int v)
//{
//	struct s_node *n;
//
//	n = malloc(sizeof(n));
//	n->value = v;
//	n->next = NULL;
//	return (n);
//}
//
//int main()
//{
//	struct s_node *new;
//
//	new = new_add(1);
//	new->next = new_add(2);
//	new->next->next = new_add(3);
//	new->next->next->next = new_add(4);
//	new->next->next->next->next = new_add(5);
//	new->next->next->next->next->next = new_add(6);
//	new->next->next->next->next->next->next = new->next->next->next->next->next;
//	printf("is looping? %d\n", is_looping(new));
//	return (0);
//}
