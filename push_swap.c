/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 19:40:54 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	short	*print_op;

	print_op= get_is_printable();
	*print_op = true;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	handle_args(&stack_a, ac, argv);
	if (!stack_a || !(*stack_a).top || is_sorted(&stack_a))
		return (0);
	size = ft_ssize(&stack_a);
	if (size <= 3)
	{
		if (size == 3)
			sort_3_nums(&stack_a);
		else if (size == 2)
			sort_2_nums(&stack_a);
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	push_swap(&stack_a, &stack_b, size);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
