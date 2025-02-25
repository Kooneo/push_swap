/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:22 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/24 14:04:40 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack **stack, int *max_val, int size)
{
	int max_pos;
	int i;
	t_node	*current;

	current = (*stack)->top;
	*max_val = current->value;
	current = current->next;
	max_pos = 0;
	i = 1;
	while (i < size)
	{
		if (current->value > *max_val)
		{
			*max_val = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

void	rotate_or_reverse_max(t_stack **b, int max_pos, int size)
{
	int	i;

	i = 0;
	if (max_pos <= size / 2)
	{
		while (i++ < max_pos)
			rb(b);
	}
	else
	{
		while (i++ < size - max_pos)
			rrb(b);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		max_pos;
	int		max_val;
	int		size;

	int down = 0; // Track numbers at the bottom of A
	while (*b && (*b)->top)
	{
		size = ft_ssize(b);
		// Find the maximum value and its position in B
		max_pos = find_max_pos(b, &max_val, size);
		// Rotate or reverse rotate to bring max to the top
		rotate_or_reverse_max(b, max_pos, size);
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
