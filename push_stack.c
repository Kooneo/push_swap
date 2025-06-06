/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:33:24 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:38 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stos(t_stack **stack_one, t_stack **stack_two)
{
	t_node	*temp;

	if (!stack_two || !*stack_two || !(*stack_two)->top)
		return ;
	temp = (*stack_two)->top;
	(*stack_two)->top = temp->next;
	if (!*stack_one)
	{
		*stack_one = malloc(sizeof(t_stack));
		if (!*stack_one)
			return ;
		(*stack_one)->top = NULL;
	}
	ft_sadd_front(stack_one, temp);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	stos(stack_b, stack_a);
	if (*(get_is_printable()))
		operation("pb");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	stos(stack_a, stack_b);
	if (*(get_is_printable()))
		operation("pa");
}
