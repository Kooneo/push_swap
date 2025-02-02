/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:18:33 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/01 18:45:29 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation(char *op)
{
	ft_putendl_fd(op, 1);
}

t_node	*ft_slast(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_sadd_back(t_stack **stack, t_node *new)
{
	t_node	*lastnode;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = malloc(sizeof(t_stack));
		if (!*stack)
			return ;
		(*stack)->top = new;
	}
	else
	{
		lastnode = ft_slast(*stack);
		lastnode->next = new;
	}
}

void	ft_sadd_front(t_stack **stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->next = (*stack)->top;
	(*stack)->top = new;
}

int ft_ssize(t_stack **stack)
{
	int size = 0;
	t_node *cur = (*stack)->top;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}
