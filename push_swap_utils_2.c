/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:30:41 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/25 15:58:03 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_push_swap(t_stack **stack_a, char **arr, const char *nptr)
{
	int			sign;
	int			i;
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
		total = total * 10 + (nptr[i++] - '0');
		if (total * sign > INT32_MAX || total * sign < INT32_MIN)
			error_and_free(arr, stack_a);
	}
	return (total * sign);
}

void	make_and_to_stack(t_stack **stack_a, char **arr, char *num)
{
	long long	n;
	t_node		*new_node;

	n = ft_atoi_push_swap(stack_a, arr, num);
	if (!(check_is_number(num)) || check_is_dup(*stack_a, n))
		error_and_free(arr, stack_a);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_and_free(arr, stack_a);
	new_node->value = n;
	new_node->next = NULL;
	ft_sadd_back(stack_a, new_node);
}
