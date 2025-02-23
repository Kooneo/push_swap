/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:02:45 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 16:12:07 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *ref, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ref[i] > ref[j])
			{
				tmp = ref[i];
				ref[i] = ref[j];
				ref[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*make_reference(t_stack **stack_a, int size)
{
	int		*ref;
	t_node	*cur;
	int		i;

	ref = malloc(size * sizeof(int));
	if (!ref)
		return (NULL);
	cur = (*stack_a)->top;
	i = 0;
	while (cur != NULL)
	{
		ref[i++] = cur->value;
		cur = cur->next;
	}
	bubble_sort(ref, size);
	return (ref);
}

void	sort_3_nums(t_stack **stack_a)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	if (!stack_a || !(*stack_a) || !(*stack_a)->top || !(*stack_a)->top->next
		|| !(*stack_a)->top->next->next)
		return ;
	num1 = (*stack_a)->top->value;
	num2 = (*stack_a)->top->next->value;
	num3 = (*stack_a)->top->next->next->value;
	max = num1;
	if (num2 > max)
		max = num2;
	if (num3 > max)
		max = num3;
	if (num1 == max)
	{
		if (num2 > num3)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
	else if (num2 == max)
	{
		if (num1 > num3)
			rra(stack_a);
		else
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
	else
	{
		if (num1 > num2)
			sa(stack_a);
	}
}

void	sort_2_nums(t_stack **stack_a)
{
	int	num1;
	int	num2;

	if (!stack_a || !(*stack_a) || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	num1 = (*stack_a)->top->value;
	num2 = (*stack_a)->top->next->value;
	if (num1 > num2)
		sa(stack_a);
}

int	init_offset(int size)
{
	int	offset;

	offset = size / 10;
	if (size <= 100)
		offset = size / 7;
	else if (size <= 7000)
		offset = size / 14;
	return (offset);
}
