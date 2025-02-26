/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:03:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:10 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	wherethelessone(t_stack **stack_a, int *i)
{
	t_node	*tmp;
	t_node	*tmp1;
	int		oc;

	oc = 0;
	tmp = (*stack_a)->top;
	tmp1 = (*stack_a)->top;
	while (tmp)
	{
		if (tmp->value < tmp1->value)
		{
			tmp1 = tmp;
			*i = oc;
		}
		tmp = tmp->next;
		oc++;
	}
}

void	sort_4_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	wherethelessone(stack_a, &i);
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