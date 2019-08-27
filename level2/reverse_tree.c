/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:57:53 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/26 18:00:33 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node *tmp;

	if (!root)
		return ;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
//
//struct s_node *new_add(int v)
//{
//	struct s_node *n;
//
//	n = malloc(sizeof(struct s_node));
//	n->value = v;
//	n->left = NULL;
//	n->right = NULL;
//	return (n);
//}
//
//int main()
//{
//	struct s_node *new;
//
//	new = new_add(94);
//	new->left = new_add(34);
//	new->right = new_add(52);
//	new->left->left = new_add(1);
//	new->left->right = new_add(99);
//	printf("new: %d\n", new->value);
//	printf("new->left: %d\n", new->left->value);
//	printf("new->right: %d\n", new->right->value);
//	printf("new->left->left: %d\n", new->left->left->value);
//	printf("new->left->right: %d\n", new->left->right->value);
//	reverse_tree(new);
//	printf("new: %d\n", new->value);
//	printf("new->left: %d\n", new->left->value);
//	printf("new->right: %d\n", new->right->value);
//	printf("new->right>left: %d\n", new->right->left->value);
//	printf("new->right->right: %d\n", new->right->right->value);
//	return (0);
//}
