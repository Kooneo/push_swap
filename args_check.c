/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:06:09 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 13:33:52 by zbakour          ###   ########.fr       */
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
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-') || (s[i] == '-'
				&& s[i + 1] == '-'))
			return (0);
		i++;
	}
	if (s[i - 1] == '-') // if entred -223-: - at the end
		return (0);
	return (1);
}

long long	ft_atoi_push_swap(const char *nptr)
{
	int		sign;
	int		i;
	long long	total;

	total = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total = total * 10 + (nptr[i] - '0');
		i++;
	}
	return (total * sign);
}
void	handle_args(t_stack **stack_a, int ac, char **argv)
{
	int		i;
	long long	n;
	t_node	*new_node;
	char	**arr;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (argv[i][0] == '\0')
			show_error(); // Add stack freeing if needed
		arr = ft_split(argv[i], ' ');
		if (!arr)
		{
			ft_free_stack(stack_a);
			show_error();
		}
		j = 0;
		while (arr[j] != NULL)
		{
			n = ft_atoi_push_swap(arr[j]);
			if (n > INT32_MAX || n < INT32_MIN) // Leaks!!!
			{
				free_array(arr);
				ft_free_stack(stack_a);
				show_error();
			}
			if (!(check_is_number(arr[j])) || check_is_dup(*stack_a, n))
			{
				free_array(arr);
				ft_free_stack(stack_a);
				show_error();
			}
			new_node = malloc(sizeof(t_node));
			if (!new_node)
			{
				free_array(arr);
				ft_free_stack(stack_a);
				show_error();
			}
			new_node->value = n;
			new_node->next = NULL;
			ft_sadd_back(stack_a, new_node);
			j++;
		}
		free_array(arr);
		i++;
	}
}
