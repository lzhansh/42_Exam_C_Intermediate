/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:37:43 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/19 17:49:41 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct s_node {
		void          *content;
		struct s_node *next;
	};

	struct s_stack {
		struct s_node *top;
	};

struct s_stack *init(void)
{
	struct s_stack *new;

	new = (struct s_stack *)malloc(sizeof(struct s_stack));
	new->top = NULL;
	return (new);
}

void *pop(struct s_stack *stack)
{
	struct s_node *tmp;
	void *cont;

	if (!stack->top)
		return (NULL);
	tmp = stack->top;
	cont = tmp->content;
	stack->top = stack->top->next;
	free(tmp);
	return (cont);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

//int main()
//{
//	struct s_stack *new = init();
//	printf("Isempty? %d\n", isEmpty(new));
//	push(new, "hey");
//	printf("Isempty? %d\n", isEmpty(new));
//	printf("peek: %s\n", peek(new));
//	push(new, "there");
//	printf("peek: %s\n", peek(new));
//	printf("1st pop: %s\n", pop(new));
//	printf("peek: %s\n", peek(new));
//	printf("2nd pop: %s\n", pop(new));
//	printf("Isempty? %d\n", isEmpty(new));
//	printf("peek: %s\n", peek(new));
//}
