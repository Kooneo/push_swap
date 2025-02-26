/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:22 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:39 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack **stack, int *max_val, int size)
{
	int		max_pos;
	int		i;
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

t_node	*get_bottom_stack(t_stack **stack)
{
	t_node	*bottom;

	bottom = (*stack)->top;
	while (bottom && bottom->next)
		bottom = bottom->next;
	return (bottom);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		max_pos;
	int		max_val;
	int		size;
	int		down;

	down = 0;
	while (*b && (*b)->top)
	{
		size = ft_ssize(b);
		max_pos = find_max_pos(b, &max_val, size);
		rotate_or_reverse_max(b, max_pos, size);
		if (down == 0 || (*b)->top->value > get_bottom_stack(a)->value)
		{
			pa(a, b);
			ra(a);
			down++;
		}
		else
			pa(a, b);
	}
}
