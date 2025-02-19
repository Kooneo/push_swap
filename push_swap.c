/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/19 13:08:22 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_el_pos(t_stack *stack, int *ref, int start, int end)
{
	int	i;

	// (void)stack;
	// (void)ref;
	i = start;
	while (i < end - 1)
	{
		if (ref[i] == stack->top->value)
			return (i);
		i++;
	}
	return (-1);
}

int	num_in_range(int num, int *ref, int start, int end)
{
	int	i;
    
	if (start < 0 || end < 0 || start > end)
		return (0);
	i = start;
	while (i < end)
	{
        if (num == ref[i])
			return (1);
		i++;
	}
	return (0);
}

void	initialize_chunk_params(int size, int params[5])
{
	params[0] = calculate_n(size);
	params[1] = (size / 2) ; // middle
	params[2] = size / params[0]; // offset
	params[3] = params[1] - params[2]; // start
	params[4] = params[1] + params[2]; // end
	// ft_printf("n: %d\n", params[0]);
	// ft_printf("middle: %d\n", params[1]);
	// ft_printf("offset: %d\n", params[2]);
	// ft_printf("start: %d\n", params[3]);
	// ft_printf("end: %d\n", params[4]);
}


// void	push_swap(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		size;
// 	t_node	*top;
// 	int		*ref;
// 	int		i;
// 	t_node		*cur;

// 	if (!stack_a || !*stack_a || !(*stack_a)->top)
// 		return ;
// 	int chunk_params[5]; // [n, middle, offset, start, end]
// 	size = ft_ssize(stack_a);
// 	top = (*stack_a)->top;
// 	ref = make_reference(stack_a, size);
// 	initialize_chunk_params(size, chunk_params);
// 	// while ((*stack_a)->top != NULL)
// 	// {
//         cur = (*stack_a)->top;
//         int chunk_size = chunk_params[4] - chunk_params[3];
//         ft_printf("chunk size: %d\n", chunk_size);
//         ft_printf("start: %d\n", chunk_params[3]);
//         ft_printf("middle: %d\n", chunk_params[1]);
// 	ft_printf("end: %d\n", chunk_params[4]);
// 		while (cur != NULL)
// 		{
// 			if (num_in_range(cur->value, ref, chunk_params[3], chunk_params[4]))
// 			{
// 				pb(stack_a, stack_b);
// 				if (cur->value <= ref[chunk_params[1]])
// 					rb(stack_b);
//                 chunk_size--;
// 			}
//             else
//                 ra(stack_a);
//             if (chunk_size == 0) 
//                 update_chunk_range(chunk_params);
//             cur = (*stack_a)->top->next;
// 		}
// 		// printf("params[4] %d\n", chunk_params[4]);
        
		
// 	// }
// 	free(ref);
// }


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

static int get_element_position(int *ref, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (ref[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

// static void push_back_to_a(t_stack **a, t_stack **b)
// {
//     int max_pos;
//     int max_val;
//     t_node *current;
//     int size_b;

//     while (*b && (*b)->top)
//     {
//         size_b = ft_ssize(b);
//         current = (*b)->top;
//         max_val = current->value;
//         max_pos = 0;
//         current = current->next;
//         for (int i = 1; i < size_b; i++)
//         {
//             if (current->value > max_val)
//             {
//                 max_val = current->value;
//                 max_pos = i;
//             }
//             current = current->next;
//         }
//         if (max_pos <= size_b / 2)
//         {
//             for (int i = 0; i < max_pos; i++)
//                 rb(b);
//         }
//         else
//         {
//             for (int i = 0; i < size_b - max_pos; i++)
//                 rrb(b);
//         }
//         pa(a, b);
//     }
// }

static void push_back_to_a(t_stack **a, t_stack **b)
{
    int max_pos;
    int max_val;
    int down = 0; // Track numbers at the bottom of A
    t_node *current;
    int size_b;

    while (*b && (*b)->top)
    {
        size_b = ft_ssize(b);
        current = (*b)->top;
        max_val = current->value;
        max_pos = 0;
        current = current->next;

        // Find the maximum value and its position in B
        for (int i = 1; i < size_b; i++)
        {
            if (current->value > max_val)
            {
                max_val = current->value;
                max_pos = i;
            }
            current = current->next;
        }

        // Rotate or reverse rotate to bring max to the top
        if (max_pos <= size_b / 2)
        {
            for (int i = 0; i < max_pos; i++)
                rb(b);
        }
        else
        {
            for (int i = 0; i < size_b - max_pos; i++)
                rrb(b);
        }

        // Find the bottom value of A
        t_node *bottom = (*a)->top;  // Start at the top
        while (bottom && bottom->next)  
            bottom = bottom->next;  // Traverse to last node

        // Now, max is at the top of B
        if (down == 0 || (*b)->top->value > bottom->value)
        {
            pa(a, b);  // Push to A
            ra(a);     // Rotate to put it at the bottom
            down++;
        }
        else
        {
            pa(a, b); // Push normally
        }
    }

    // Reverse rotate A to bring everything back
    // while (down-- > 0)
    //     rra(a);
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int *ref;
    int params[5];
    int start;
    int end;
    int offset;

    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return;
    size = ft_ssize(stack_a);
    if (size == 3)
    {
        sort_3_nums(stack_a);
        return;
    }
    ref = make_reference(stack_a, size);
    initialize_chunk_params(size, params);
    start = params[3];
    end = params[4];
    offset = params[2];
    while ((*stack_a)->top != NULL)
    {
        int current_start = (start < 0) ? 0 : start;
        int current_end = (end > size) ? size : end;
        if (current_start >= current_end)
            break;
        int current_chunk_middle = (current_end + current_start) / 2;
        int rotations = 0;
        int current_size = ft_ssize(stack_a);
        while (rotations < current_size)
        {
            int val = (*stack_a)->top->value;
            int pos = get_element_position(ref, size, val);
            if (pos >= current_start && pos < current_end)
            {
                pb(stack_a, stack_b);
                int b_pos = get_element_position(ref, size, (*stack_b)->top->value);
                if (b_pos < current_chunk_middle)
                    rb(stack_b);
                rotations = 0;
                current_size = ft_ssize(stack_a);
            }
            else
            {
                ra(stack_a);
                rotations++;
            }
        }
        start -= offset;
        end += offset;
    }
    push_back_to_a(stack_a, stack_b);
    free(ref);
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
		// print_stacks(stack_a, stack_b);
		push_swap(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
	}
	free_stacks(stack_a, stack_b);
	return (0);
}

