/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:03:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/28 18:13:36 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_pos(t_stack **stack_a, int *i)
{
	t_node	*current;
	int		min_value;
	int		min_index;

	current = (*stack_a)->top;
	min_value = current->value;
	min_index = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			*i = min_index;
		}
		current = current->next;
		min_index++;
	}
}

void	sort_4_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	get_min_pos(stack_a, &i);
	if (i == 1)
		sa(stack_a);
	else if (i == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (i == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3_nums(stack_a);
	pa(stack_a, stack_b);
}
