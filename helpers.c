/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:02:45 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/16 16:13:56 by zbakour          ###   ########.fr       */
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

void	update_chunk_range(int *params)
{
	ft_printf("start: %d\n", params[3]);
	ft_printf("end: %d\n", params[4]);
	params[3] -= params[2];
	params[4] += params[2];
	ft_printf("start: %d\n", params[3]);
	ft_printf("end: %d\n", params[4]);
}

int	calculate_n(int size)
{
	int	n;

	n = 18;
	if (size <= 10)
		n = 5;
	else if (size <= 150)
		n = 8;
	return (n);
}
