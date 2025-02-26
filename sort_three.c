/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:07:50 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:15 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num1_is_max(t_stack **stack_a, int num2, int num3)
{
	if (num2 > num3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
		ra(stack_a);
}

void	num2_is_max(t_stack **stack_a, int num1, int num3)
{
	if (num1 > num3)
		rra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
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
		num1_is_max(stack_a, num2, num3);
	else if (num2 == max)
		num2_is_max(stack_a, num1, num3);
	else
		if (num1 > num2)
			sa(stack_a);
}
