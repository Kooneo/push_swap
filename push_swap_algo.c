/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:00:50 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:36 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_index(int *index, int *offset, int size)
{
	if ((*offset) < size - 1)
		(*offset)++;
	if ((*index) < (*offset))
		(*index)++;
}

static void	pb_and_sb(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	if ((*stack_b)->top && (*stack_b)->top->next
		&& (*stack_b)->top->value < (*stack_b)->top->next->value)
		sb(stack_b);
}

static void	pb_and_rb(t_stack **stack_a, t_stack **stack_b)
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
