/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:30:41 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/24 12:54:05 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_and_to_stack(t_stack **stack_a, char **arr, char *num)
{
	long long	n;
	t_node		*new_node;

	n = ft_atoi_push_swap(num);
	if (n > INT32_MAX ||  n < INT32_MIN || (!(check_is_number(num))
			|| check_is_dup(*stack_a, n)) || ft_strlen(num) > 11)
		error_and_free(arr, stack_a);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_and_free(arr, stack_a);
	new_node->value = n;
	new_node->next = NULL;
	ft_sadd_back(stack_a, new_node);
}
