/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:22 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/24 11:53:49 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		max_pos;
	int		max_val;
	t_node	*current;
	int		size;
	int		i;

	int down = 0; // Track numbers at the bottom of A
	while (*b && (*b)->top)
	{
		size = ft_ssize(b);
		current = (*b)->top;
		max_val = current->value;
		max_pos = 0;
		current = current->next;
		// Find the maximum value and its position in B
		i = 1;
		while (i < size)
		{
			if (current->value > max_val)
			{
				max_val = current->value;
				max_pos = i;
			}
			current = current->next;
			i++;
		}
		// Rotate or reverse rotate to bring max to the top
		if (max_pos <= size / 2)
		{
			i = 0;
			while (i++ < max_pos)
				rb(b);
		}
		else
		{
			i = 0;
			while (i++ < size - max_pos)
				rrb(b);
		}
		// Find the bottom value of A
		t_node *bottom = (*a)->top; // Start at the top
		while (bottom && bottom->next)
			bottom = bottom->next; // Traverse to last node
		// Now, max is at the top of B
		if (down == 0 || (*b)->top->value > bottom->value)
		{
			pa(a, b); // Push to A
			ra(a);    // Rotate to put it at the bottom
			down++;
		}
		else
			pa(a, b);
	}
}
