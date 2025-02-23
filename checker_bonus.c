/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:25:27 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 20:29:03 by zbakour          ###   ########.fr       */
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

short is_op(char *to_check, const char *op)
{
	return (ft_strcmp(to_check, op) == 0);
}

void do_operation(t_stack **a, t_stack **b, char *op)
{
	if (is_op(op, "sa"))
		sa(a);
	else if (is_op(op, "sb"))
		sb(b);
	else if (is_op(op, "ss"))
		ss(a, b);
	else if (is_op(op, "pa"))
		pa(a, b);
	else if (is_op(op, "pb"))
		pb(a, b);
	else if (is_op(op, "ra"))
		ra(a);
	else if (is_op(op, "rb"))
		rb(b);
	else if (is_op(op, "rr"))
		rr(a, b);
	else if (is_op(op, "rra"))
		rra(a);
	else if (is_op(op, "rrb"))
		rrb(b);
	else if (is_op(op, "rrr"))
		rrr(a, b);
	else
	{
		free_stacks(a, b);
		free(op);
		show_error();
	}	
}

int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	short	*print_op;

	stack_a = NULL;
	stack_b = NULL;
	print_op= get_is_printable();
	*print_op = false;
	if (ac != 1)
	{
		handle_args(&stack_a, ac, argv);
		char *operation = ft_strtrim(get_next_line(0), "\n\t\v");
		while (operation)
		{
			do_operation(&stack_a, &stack_b, operation);
			free(operation);
			operation = ft_strtrim(get_next_line(0), "\n\t\v");
		}
		if (!is_sorted(&stack_a))
			ft_putendl_fd("KO", 1);
		else
			ft_putendl_fd("OK", 1);
		free_stacks(&stack_a, &stack_b);
	}
	free_stacks(&stack_a, &stack_b);
	return (0);
}
