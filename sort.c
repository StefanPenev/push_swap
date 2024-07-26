/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:51:58 by spenev            #+#    #+#             */
/*   Updated: 2024/07/26 15:11:27 by stefan           ###   ########.fr       */
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

int	ft_lstfind_ind_of_max_value(t_lst *lst)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = lst->value;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if (lst->value > max_value)
		{
			max_ind = it;
			max_value = lst->value;
		}
		lst = lst->next;
		it++;
	}
	return (max_ind);
}

void	lets_sort_any_stk(t_lst **stack, char stk_name)
{
	int	max_index;
	int	half_size;

	max_index = ft_lstfind_ind_of_max_value(*stack);
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

void	sort(t_lst **a_stk, t_lst **b_stk)
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
	lets_sort_any_stk(a_stk, 'a');
}

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
