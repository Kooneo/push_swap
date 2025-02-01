/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:06 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/01 18:03:03 by zbakour          ###   ########.fr       */
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

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    t_node  *current;
    int     biggest;
    int     index;

    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return;
    current = (*stack_a)->top;
    biggest = current->value;
    index = 0;
    while (current)
    {
        if (current->value >= biggest)
        {
            biggest = current->value;
            while (index)
            {
                index--;
                ra(stack_a);
            }
            pb(stack_a, stack_b);
            index = 0;
            current = (*stack_a)->top;
        }
        else
        {
            index++;
            current = current->next;
        }
    }
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
		print_stacks(stack_a, stack_b);
        push_swap(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
    }
    // Free memory before exit
    free_stacks(stack_a, stack_b);
    return (0);
}