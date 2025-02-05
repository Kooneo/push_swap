/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/05 18:16:21 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_stack *stack)
{
    t_node *current;

    if (!stack)
        return;
    current = stack->top;
    while (current)
    {
        ft_printf("%d\n", current->value);
        current = current->next;
    }
}

void print_stacks(t_stack *a, t_stack *b)
{
    ft_printf("─── A ───\n");
    print_stack(a);
    ft_printf("─── B ───\n");
    print_stack(b);
    ft_printf("\n");
}

int check_is_dup(t_stack *stack, int n)
{
    t_node *current;

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

void handle_args(t_stack **stack_a, int ac, char **argv)
{
    int     i;
    int     n;
    t_node  *new_node;
    char    **arr;
    int     j;

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
            new_node = malloc(sizeof(t_node));
            if (!new_node)
                show_error();
            new_node->value = n;
            new_node->next = NULL;
            ft_sadd_back(stack_a, new_node);
            j++;
        }
        free_array(arr);
        i++;
    }
}

int get_max_value(t_stack *stack)
{
    t_node *current;
    int max;

    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    max = current->value;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

/*
n: is a constant that is set depending on the size of the stack, and it helps in calculating the offset (or chunk size),
   for 10 numbers or less n = 5, for 150 or less n = 8, and more than 150 n = 18. these numbers are just starting points;
   you can calibrate them to the performance you prefer.

middle: as the name suggests, this is the middle of the sorted array(stack size / 2).

offset: this variable is the chunk size, which equals (stack size / n).

start: this is the start of the range that will be pushed, it is an index in the sorted array (middle - offset).

end: this is the end of the range that will be pushed, it is an index in the sorted array(middle + offset).
*/
int calculate_n(int size)
{
    int n = 18;
    if (size <= 10)
        n = 5;
    else if (size <= 150)
        n = 8;
    return (n);
}

int  *make_reference(t_stack **stack_a, int size)
{
    int *ref;

    ref = malloc(size * sizeof(int));
    if (!ref)
        return (NULL);
    t_node *cur = (*stack_a)->top;
    int i = 0;
    while (cur != NULL)
    {
        ref[i++] = cur->value;
        cur = cur->next;
    }
    i = 0;
    
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - i - 1)
        {
            if (ref[j] > ref[j + 1])
            {
                int tmp = ref[j];
                ref[j] = ref[j + 1];
                ref[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    return (ref);
}

int num_in_range(int num, int *ref, int start, int end)
{
    int i = start - 1;
    
    while (i < end)
    {
        if (num == ref[i])
            return (1);
        i++;
    }
    return (0);
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return;

    int size = ft_ssize(stack_a);
    int n = calculate_n(size);
    int offset = size / n;
    int middle = size / 2;
    int start = middle - offset;
    int end = middle + offset;
    int *ref = make_reference(stack_a, size);
    int chunk_size = end - start;
    while ((*stack_a) && (*stack_a)->top)
    {
        t_node *top = (*stack_a)->top;
        while (top != NULL)
        {
            if (num_in_range(top->value, ref, start, end))
            {
                pb(stack_a, stack_b);
                if (top->value < ref[middle])
                    rb(stack_b);
                chunk_size--;
                top = (*stack_a)->top;
            } else
                ra(stack_a);
            if (chunk_size == 0)
            {
                start += offset;
                end += offset;
                chunk_size = end - start;
            }
            if (top)
                top = top->next;
        }   
    }
    free(ref);
}

int main(int ac, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

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
