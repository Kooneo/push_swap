/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:32:10 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 16:47:25 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_fs(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack **stack_a)
{
	if (stack_a)
		swap_fs(*stack_a);
	operation("sa");
}

void	sb(t_stack **stack_b)
{
	if (stack_b)
		swap_fs(*stack_b);
	operation("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		swap_fs(*stack_a);
	if (stack_b)
		swap_fs(*stack_b);
	operation("ss");
}
