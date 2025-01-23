/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/01/23 17:32:26 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_args(t_list **stack_a, int ac, char **argv)
{
	int	i;

	i = 1;
	while (i < ac )
	{
        int n = ft_atoi(argv[i]);
        t_list *num = ft_lstnew(ft_itoa(n));
        ft_lstadd_back(stack_a, num);
        i++;
	}
}

void print_stack(t_list *stack)
{
    // ft_printf("<-- HEAD --> \t\n");
    while (stack != NULL)
    {
        ft_printf("%s\n", stack->content);
        stack = stack->next;
    }
    // ft_printf("<-- TAIL --> \t\n");
}

int	main(int ac, char **argv)
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
	if (ac != 1)
	{
        handle_args(&stack_a, ac, argv);
        print_stack(stack_a);
        print_stack(stack_b);
        ft_printf("------------------------\n");
        pb(&stack_b, &stack_a);
        print_stack(stack_a);
        print_stack(stack_b);
	}
	return (0);
}
