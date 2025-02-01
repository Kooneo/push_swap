/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/01 16:13:21 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_args(t_list **stack_a, int ac, char **argv)
{
	int		i;
	int		n;
	t_list	*num;
	char	**arr;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (argv[i][0] == '\0')
			show_error();
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j] != NULL)
		{
			n = ft_atoi(arr[j]);
			if (!(check_is_number(arr[j])) || check_is_dup(*stack_a, n))
				show_error();
			num = ft_lstnew(ft_itoa(n));
			ft_lstadd_back(stack_a, num);
			j++;
		}
		free(arr);
		i++;
	}
}

// Returns the maximum value in the stack
int get_max_value(t_list *stack) {
    int max = ft_atoi(stack->content);
    while (stack) {
        if (ft_atoi(stack->content) > max)
            max = ft_atoi(stack->content);
        stack = stack->next;
    }
    return max;
}


void	print_stack(t_list *stack)
{
	// ft_printf("<-- HEAD --> \t\n");
	while (stack != NULL)
	{
		ft_printf("%s\n", stack->content);
		stack = stack->next;
	}
	// ft_printf("<-- TAIL --> \t\n");
}
// Print stacks with labels
void print_stacks(t_list *a, t_list *b) {
    ft_printf("─── A ───\n");
    print_stack(a);
    ft_printf("─── B ───\n");
    print_stack(b);
    ft_printf("\n");
}

// Call this after EVERY operation in push_swap():


void	push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*cur;
	int		biggest;
	int		index;

	cur = *stack_a;
	biggest = ft_atoi((char *)cur->content);
	index = 0;
	while (cur != NULL)
	{
		if (ft_atoi((char *)cur->content) >= biggest)
		{
			biggest = ft_atoi((char *)cur->content);
			while (index)
			{
				index--;
				ra(stack_a);
			}
			pb(stack_b, stack_a);
			index = 0;
			cur = *stack_a;
		}
		else {
			index++;
			cur = cur->next;
		}
	}
}

int	main(int ac, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		handle_args(&stack_a, ac, argv);
		// ft_printf("---------stack a: ---------------\n");
		// print_stack(stack_a);
		// ft_printf("--------- operations: -----------\n");
		// ft_printf("\n\n\n");
		push_swap(&stack_a, &stack_b);
		// ft_printf("---------stack a: ---------------\n");
		// print_stack(stack_a);
		// pb(&stack_a, &stack_b);
		// ft_printf("---------stack b: ---------------\n");
		// print_stack(stack_b);
	}
	return (0);
}
