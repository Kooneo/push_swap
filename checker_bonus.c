/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:25:27 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 22:56:38 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	is_op(char *to_check, const char *op)
{
	return (ft_strcmp(to_check, op) == 0);
}

int	do_operation(t_stack **a, t_stack **b, char *op)
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
		return (0);
	return (1);
}

void	handle_operations(t_stack **a, t_stack **b, char *op)
{
	if (do_operation(a, b, op))
		;
	else
	{
		free_stack(a);
		free_stack(b);
		free(op);
		get_next_line(-99);
		show_error();
	}
}

void	check_result(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a) || (*stack_b && ft_ssize(stack_b) > 0))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	free_stacks(stack_a, stack_b);
}

int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	short	*print_op;
	char	*operation;
	char	*read_line;

	stack_a = NULL;
	stack_b = NULL;
	print_op = get_is_printable();
	*print_op = false;
	if (ac != 1)
	{
		handle_args(&stack_a, ac, argv);
		read_line = get_next_line(0);
		while (read_line)
		{
			operation = ft_strtrim(read_line, "\n\t\v");
			free(read_line);
			handle_operations(&stack_a, &stack_b, operation);
			free(operation);
			read_line = get_next_line(0);
		}
		check_result(&stack_a, &stack_b);
		get_next_line(-99);
		free(read_line);
	}
	free(print_op);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
