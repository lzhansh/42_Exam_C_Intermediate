/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:30:27 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/19 00:07:52 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
       int           value;
       struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int height;
	int i;
	int res;

	if (!root)
		return (-1);
	i = 0;
	height = 0;
	while (root->nodes[i])
	{
		res = 1 + height_tree(root->nodes[i++]);
		height = (res > height) ? res : height;
	}
	return (height);
}

//struct s_node *add_new(int n)
//{
//	struct s_node *new;
//
//	if (!(new = (struct s_node *)malloc(sizeof(struct s_node))))
//		return (NULL);
//	new->value = n;
//	new->nodes = malloc(1000);
//	return (new);
//}
//
//int main(void)
//{
//	struct s_node *t = add_new(94);
//	t->nodes[0] = add_new(34);
//	t->nodes[1] = add_new(52);
//
//	t->nodes[0]->nodes[0] = add_new(1);
//	t->nodes[0]->nodes[1] = add_new(99);
//	t->nodes[0]->nodes[2] = add_new(11);
//	
//	t->nodes[0]->nodes[1]->nodes[0] = add_new(13);
//
//	printf("%d\n", height_tree(t));
//	return (0);
//}
