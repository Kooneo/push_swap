/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:06:09 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/26 23:03:49 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_dup(t_stack *stack, int n)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == n)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s) == 1 && (s[i] == '-' || s[i] == '+'))
			return (0);
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+'))
			return (0);
		if ((i != 0 && (s[i] == '-' || s[i] == '+')))
			return (0);
		i++;
	}
	return (1);
}

void	error_and_free(char **arr, t_stack **stack)
{
	if (arr)
		free_array(arr);
	free_stack(stack);
	show_error();
}

bool	is_onlychar(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (true);
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (true);
	return (false);
}

void	handle_args(t_stack **stack_a, int ac, char **argv)
{
	char		**arr;
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		if (argv[i][0] == '\0' || is_onlychar(argv[i], ' '))
			error_and_free(NULL, stack_a);
		arr = ft_split(argv[i], ' ');
		if (!arr)
			error_and_free(arr, stack_a);
		j = 0;
		while (arr[j] != NULL)
		{
			make_and_to_stack(stack_a, arr, arr[j]);
			j++;
		}
		free_array(arr);
		i++;
	}
}
