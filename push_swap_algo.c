/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:00:50 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 17:05:31 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_to_a(t_stack **a, t_stack **b)
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

void	move_index(int *index, int *offset, int size)
{
	if ((*offset) < size - 1)
		(*offset)++;
	if ((*index) < (*offset))
		(*index)++;
}

static void pb_and_sb(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	if ((*stack_b)->top && (*stack_b)->top->next
		&& (*stack_b)->top->value < (*stack_b)->top->next->value)
		sb(stack_b);
}

static void pb_and_rb(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	if ((*stack_b)->top->next)
		rb(stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*ref;
	int	index;
	int	offset;

	ref = make_reference(stack_a, size);
	index = 0;
	offset = init_offset(size);
	while ((*stack_a)->top != NULL)
	{
		if ((*stack_a)->top->value <= ref[index])
		{
			pb_and_rb(stack_a, stack_b);
			move_index(&index, &offset, size);
		}
		else if ((*stack_a)->top->value <= ref[offset])
		{
			pb_and_sb(stack_a, stack_b);
			move_index(&index, &offset, size);
		}
		else if ((*stack_a)->top->next)
			ra(stack_a);
	}
	push_back_to_a(stack_a, stack_b);
	free(ref);
}
