/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/01/23 19:07:36 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_dup(t_list *lst, int num)
{
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (num == ft_atoi(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

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

int	main(int ac, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		handle_args(&stack_a, ac, argv);
		ft_printf("---------stack a: ---------------\n");
		print_stack(stack_a);
		ft_printf("--------- operations: -----------\n");
		pb(&stack_b, &stack_a);
		ft_printf("\n\n\n");
		ft_printf("---------stack a: ---------------\n");
		print_stack(stack_a);
		ft_printf("---------stack b: ---------------\n");
		print_stack(stack_b);
	}
	return (0);
}
