/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:25:27 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/20 12:28:53 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("─── A ───\n");
	print_stack(a);
	ft_printf("─── B ───\n");
	print_stack(b);
	ft_printf("\n");
}

int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		handle_args(&stack_a, ac, argv);
		// push_swap(&stack_a, &stack_b);
        print_stacks(stack_a, stack_b);
	}
	free_stacks(stack_a, stack_b);
	return (0);
}
