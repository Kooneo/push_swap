/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:36:50 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 18:52:57 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_node	*firstnode;

	if (!stack || !*stack || !(*stack)->top || !(*stack)->top->next)
		return ;
	firstnode = (*stack)->top;
	(*stack)->top = firstnode->next;
	firstnode->next = NULL;
	ft_sadd_back(stack, firstnode);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	if (*(get_is_printable()))
		operation("ra");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	if (*(get_is_printable()))
		operation("rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	if (*(get_is_printable()))
		operation("rr");
}
