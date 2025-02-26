/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:41:40 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:32 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = (*stack)->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

short	is_sorted(t_stack **stack_a)
{
	t_node	*current;

	current = (*stack_a)->top;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (current->value > current->next->value)
				return (0);
		}
		current = current->next;
	}
	return (1);
}
