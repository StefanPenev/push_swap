/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:51:58 by spenev            #+#    #+#             */
/*   Updated: 2024/07/27 11:15:28 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sort a small stack (up to three elements)
void	mini_sort(t_lst **stack)
{
	int	max_index;

	if (ft_listsize(*stack) == 2 && (*stack)->value > (*stack)->next->value)
		swap_stack(stack, 'a');
	else
	{
		max_index = get_max_value_index(*stack);
		if (max_index == 0)
			rotate_stack(stack, 'a');
		else if (max_index == 1)
			reverse_rotate_stack(stack, 'a');
		if ((*stack)->value > (*stack)->next->value)
			swap_stack(stack, 'a');
	}
}

/* Sort a stack by rotating or reverse rotating 
based on the maximum value's position */
static	void	sort_stack(t_lst **stack, char stk_name)
{
	int	max_index;
	int	half_size;

	max_index = get_max_value_index(*stack);
	half_size = ft_listsize(*stack) / 2;
	if (max_index > half_size)
	{
		while (!is_stack_sorted(*stack))
			reverse_rotate_stack(stack, stk_name);
	}
	else
	{
		while (!is_stack_sorted(*stack))
			rotate_stack(stack, stk_name);
	}
}

//Sort the stack using the actions with the minimum total actions
static	void	sort(t_lst **a_stk, t_lst **b_stk)
{
	t_actions	*min_actions;

	min_actions = (t_actions *)malloc(sizeof(t_actions));
	if (!min_actions)
		return ;
	while (*b_stk)
	{
		find_best_action(a_stk, b_stk, min_actions);
		if (min_actions->mode == 1)
			rr_mode(a_stk, b_stk, *min_actions);
		if (min_actions->mode == 2)
			rrr_mode(a_stk, b_stk, *min_actions);
		if (min_actions->mode == 3)
			ra_and_rrb_mode(a_stk, b_stk, *min_actions);
		if (min_actions->mode == 4)
			rb_and_rra_mode(a_stk, b_stk, *min_actions);
		push(a_stk, b_stk, 'a');
	}
	free(min_actions);
	sort_stack(a_stk, 'a');
}

//Perform the initial sorting of stack
void	initial_sort(t_lst **a_stk, t_lst **b_stk)
{
	int		lst_len;
	int		med_value;
	int		med_len;

	if (is_stack_sorted(*a_stk))
		exit (EXIT_SUCCESS);
	lst_len = ft_listsize(*a_stk);
	med_len = lst_len / 2;
	med_value = get_median_value(*a_stk, lst_len);
	while (lst_len > 3)
	{
		if (med_value < (*a_stk)->value && lst_len > med_len && med_len > 100)
			rotate_stack(a_stk, 'a');
		else
		{
			push(b_stk, a_stk, 'b');
			lst_len--;
		}
	}
	mini_sort(a_stk);
	sort(a_stk, b_stk);
}
