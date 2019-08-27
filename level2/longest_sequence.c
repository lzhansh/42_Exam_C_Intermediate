/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:17:06 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/26 16:14:37 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void ft_seq(struct s_node *node, int *res, int target, int curlen)
{
	if (!node)
		return ;
	if (node->value == target)
		curlen++;
	else
		curlen = 1;
	*res = (curlen > *res) ? curlen : (*res);
	if (node->left)
		ft_seq(node->left, res, node->value+1, curlen);
	if (node->right)
		ft_seq(node->right, res, node->value+1, curlen);
}

int	longest_sequence(struct s_node *node)
{
	int res;

	if (!node)
		return (0);
	res = 0;
	ft_seq(node, &res, node->value, 0);
	return (res);
}
//
//struct s_node *new_add(int v)
//{
//	struct s_node *n;
//
//	n = (struct s_node *)malloc(sizeof(struct s_node));
//	n->value = v;
//	n->left = NULL;
//	n->right = NULL;
//	return (n);
//}
//
//int main()
//{
//	struct s_node *new;
//	new = new_add(10);
//	new->left = new_add(5);
//	new->left->left = new_add(9);
//	new->left->right = new_add(9);
//	new->left->left->left = new_add(8);
//	new->left->left->right = new_add(13);
//	printf("%d\n", longest_sequence(new));
//}
//
