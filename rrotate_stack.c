/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:37:35 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/01 17:38:00 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **stack)
{
	t_node	*prelast;
	t_node	*lastnode;

	if (!stack || !*stack || !(*stack)->top || !(*stack)->top->next)
		return ;
	prelast = (*stack)->top;
	while (prelast->next && prelast->next->next)
		prelast = prelast->next;
	lastnode = prelast->next;
	prelast->next = NULL;
	lastnode->next = (*stack)->top;
	(*stack)->top = lastnode;
}

void	rra(t_stack **stack_a)
{
	rrotate(stack_a);
	operation("rra");
}

void	rrb(t_stack **stack_b)
{
	rrotate(stack_b);
	operation("rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	operation("rrr");
}
