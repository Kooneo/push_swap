/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:18:33 by zbakour           #+#    #+#             */
/*   Updated: 2025/01/23 17:49:44 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation(char *op)
{
	ft_putendl_fd(op, 1);
}

// Swap first 2 el
void	swap_fs(t_list **stack)
{
	t_list	*fel;
	t_list	*sel;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	fel = *stack;
	sel = fel->next;
	fel->next = sel->next;
	sel->next = fel;
	*stack = sel;
}

/*
	sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void	sa(t_list **stack_a)
{
	swap_fs(stack_a);
	operation("sa");
}

/*
	sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
*/
void	sb(t_list **stack_b)
{
	swap_fs(stack_b);
	operation("sb");
}

// ss : sa and sb at the same time.
void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	operation("ss");
}

// takes el from stack_two to the stack_one
void	stos(t_list **stack_one, t_list **stack_two)
{
	t_list	*temp;

	if (!stack_two || !*stack_two)
		return ;
	temp = *stack_two;
	*stack_two = (*stack_two)->next;
	temp->next = NULL;
	ft_lstadd_front(stack_one, temp);
}

/*
	pa (push a): Take the first element at
	the top of b and put it at the top of a.
	Do nothing if b is empty.
*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	stos(stack_a, stack_b);
	operation("pa");
}

/*
	pb (push b): Take the first element at
	the top of a and put it at the top of b.
	Do nothing if a is empty.
*/
void	pb(t_list **stack_b, t_list **stack_a)
{
	stos(stack_b, stack_a);
	operation("pb");
}

void	rotate(t_list **stack)
{
	t_list	*firstnode;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	firstnode = *stack;
	*stack = firstnode->next;
	firstnode->next = NULL;
	ft_lstadd_back(stack, firstnode);
}

/*
	ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	ra(t_list **stack_a)
{
	rotate(stack_a);
	operation("ra");
}

/*
	rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/
void	rb(t_list **stack_b)
{
	rotate(stack_b);
	operation("rb");
}

// rr : ra and rb at the same time.
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	operation("rr");
}

// rrotate: Reverse rotate a stack
void	rrotate(t_list **stack)
{
	t_list	*prelast;
	t_list	*lastnode;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prelast = *stack;
	while (prelast->next && prelast->next->next)
		prelast = prelast->next;
	lastnode = prelast->next;
	prelast->next = NULL;
	lastnode->next = *stack;
	*stack = lastnode;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	operation("rra");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	operation("rrb");
}

// rrr : rra and rrb at the same time.
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	operation("rrr");
}
