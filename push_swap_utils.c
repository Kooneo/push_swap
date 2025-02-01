/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:41:40 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/01 18:09:04 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	check_is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9' ) || s[i] == '-') || (s[i] == '-' && s[i + 1] == '-'))
			return (0);
		i++;
	}
    if (s[i - 1] == '-') // if entred -223-: - at the end
        return (0);
	return (1);
}

void free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    free_stack(stack_a);
    free_stack(stack_b);
}
