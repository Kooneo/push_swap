/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:03:33 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 14:56:44 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node			*top;
}		t_stack;

void	handle_args(t_stack **stack_a, int ac, char **argv);
int		*make_reference(t_stack **stack_a, int size);
void	update_chunk_range(int *params);
int		calculate_n(int size);
void	show_error(void);
int		check_is_dup(t_stack *stack, int n);
int		check_is_number(char *s);
void	free_stack(t_stack **stack);
void	free_array(char **arr);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);
int		ft_ssize(t_stack **stack);
// Utils functions
void	operation(char *op);
t_node	*ft_slast(t_stack *stack);
void	ft_sadd_back(t_stack **stack, t_node *new);
void	ft_sadd_front(t_stack **stack, t_node *new);

// Stack operations
void	swap_fs(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	stos(t_stack **stack_one, t_stack **stack_two);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif