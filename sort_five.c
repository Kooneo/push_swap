/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:02:55 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/28 18:13:28 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_or_reverse_min(t_stack **a, int min_pos, int size)
{
	int	i;

	i = 0;
	if (min_pos <= size / 2)
	{
		while (i++ < min_pos)
			ra(a);
	}
	else
	{
		while (i++ < size - min_pos)
			rra(a);
	}
}

static void	move_min_to_top(t_stack **stack_a)
{
	t_node	*current;
	int		min_value;
	int		min_index;
	int		i;

	current = (*stack_a)->top;
	min_value = current->value;
	min_index = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	rotate_or_reverse_min(stack_a, min_index, ft_ssize(stack_a));
}

void	sort_5_nums(t_stack **stack_a, t_stack **stack_b)
{
	move_min_to_top(stack_a);
	pb(stack_a, stack_b);
	move_min_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_3_nums(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
