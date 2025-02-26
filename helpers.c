/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:02:45 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:42 by zbakour          ###   ########.fr       */
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

short	*get_is_printable(void)
{
	static short	is_printable;

	return (&is_printable);
}
