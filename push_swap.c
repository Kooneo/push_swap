/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/23 13:48:08 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nums(t_stack **stack_a)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	if (!stack_a || !(*stack_a) || !(*stack_a)->top || !(*stack_a)->top->next
		|| !(*stack_a)->top->next->next)
		return ;
	num1 = (*stack_a)->top->value;
	num2 = (*stack_a)->top->next->value;
	num3 = (*stack_a)->top->next->next->value;
	max = num1;
	if (num2 > max)
		max = num2;
	if (num3 > max)
		max = num3;
	if (num1 == max)
	{
		if (num2 > num3)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
	else if (num2 == max)
	{
		if (num1 > num3)
			rra(stack_a);
		else
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
	else
	{
		if (num1 > num2)
			sa(stack_a);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		max_pos;
	int		max_val;
	t_node	*current;
	int		size;
	int		i;

	int down = 0; // Track numbers at the bottom of A
	while (*b && (*b)->top)
	{
		size = ft_ssize(b);
		current = (*b)->top;
		max_val = current->value;
		max_pos = 0;
		current = current->next;
		// Find the maximum value and its position in B
		i = 1;
		while (i < size)
		{
			if (current->value > max_val)
			{
				max_val = current->value;
				max_pos = i;
			}
			current = current->next;
			i++;
		}
		// Rotate or reverse rotate to bring max to the top
		if (max_pos <= size / 2)
		{
			i = 0;
			while (i++ < max_pos)
				rb(b);
		}
		else
		{
			i = 0;
			while (i++ < size - max_pos)
				rrb(b);
		}
		// Find the bottom value of A
		t_node *bottom = (*a)->top; // Start at the top
		while (bottom && bottom->next)
			bottom = bottom->next; // Traverse to last node
		// Now, max is at the top of B
		if (down == 0 || (*b)->top->value > bottom->value)
		{
			pa(a, b); // Push to A
			ra(a);    // Rotate to put it at the bottom
			down++;
		}
		else
			pa(a, b);
	}
}

int	init_offset(int size)
{
	int	offset;

	offset = size / 10;
	if (size <= 100)
		offset = size / 7;
	else if (size <= 7000)
		offset = size / 14;
	return (offset);
}

void	move_index(int *index, int *offset, int size)
{
	if ((*offset) < size - 1)
		(*offset)++;
	if ((*index) < (*offset))
		(*index)++;
}

short	is_sorted(t_stack **stack_a)
{
	t_node *current;

	current = (*stack_a)->top;
	short is_not_sorted = 0;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (current->value > current->next->value)
				is_not_sorted = 1;
		}
		current = current->next;
	}
	return (!is_not_sorted);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	*ref;
	int	index;
	int	offset;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return ;
	size = ft_ssize(stack_a);
	if (size == 3)
		return (sort_3_nums(stack_a));
	ref = make_reference(stack_a, size);
	index = 0;
	offset = init_offset(size);
	while ((*stack_a)->top != NULL)
	{
		if ((*stack_a)->top->value <= ref[index])
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->top->next)
				rb(stack_b);
			move_index(&index, &offset, size);
		}
		else if ((*stack_a)->top->value <= ref[offset])
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->top && (*stack_b)->top->next
				&& (*stack_b)->top->value < (*stack_b)->top->next->value)
				sb(stack_b);
			move_index(&index, &offset, size);
		}
		else if ((*stack_a)->top->next)
			ra(stack_a);
	}
	push_back_to_a(stack_a, stack_b);
	free(ref);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("─── A ───\n");
	print_stack(a);
	ft_printf("─── B ───\n");
	print_stack(b);
	ft_printf("\n");
}

int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		handle_args(&stack_a, ac, argv);
		print_stacks(stack_a, stack_b);
		push_swap(&stack_a, &stack_b);
	}
	free_stacks(stack_a, stack_b);
	return (0);
}
