/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:41:40 by zbakour           #+#    #+#             */
/*   Updated: 2025/01/24 13:54:15 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

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
