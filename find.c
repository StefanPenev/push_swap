/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:12:44 by spenev            #+#    #+#             */
/*   Updated: 2024/07/27 11:12:46 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Return the larger of two values
static int	find_max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

//Overwrite the values of one t_actions with another
static	void	overwritte_actions(t_actions *min_actions, t_actions *cur_act)
{
	min_actions->ra = cur_act->ra;
	min_actions->rb = cur_act->rb;
	min_actions->rra = cur_act->rra;
	min_actions->rrb = cur_act->rrb;
	min_actions->total = cur_act->total;
	min_actions->mode = cur_act->mode;
}

//Find the best place in stack a to insert the current element from stack b
static	int	find_best_place_in_a(t_lst *a_stk, t_lst *b_stk)
{
	int	best_value;
	int	best_ind;
	int	it;

	best_value = a_stk->value;
	best_ind = 0;
	it = 1;
	a_stk = a_stk->next;
	while (a_stk)
	{
		if ((best_value > a_stk->value && best_value < b_stk->value) \
		|| (a_stk->value > b_stk->value && (best_value < b_stk->value \
		|| best_value > a_stk->value)))
		{
			best_ind = it;
			best_value = a_stk->value;
		}
		a_stk = a_stk->next;
		it++;
	}
	return (best_ind);
}

//Find the best mode of operation for the current action
static	void	find_best_mode(t_actions *cur_act)
{
	cur_act->total = INT_MAX;
	if (cur_act->total > find_max_value(cur_act->ra, cur_act->rb))
	{
		cur_act->total = find_max_value(cur_act->ra, cur_act->rb);
		cur_act->mode = 1;
	}
	if (cur_act->total > find_max_value(cur_act->rra, cur_act->rrb))
	{
		cur_act->total = find_max_value(cur_act->rra, cur_act->rrb);
		cur_act->mode = 2;
	}
	if (cur_act->total > cur_act->ra + cur_act->rrb)
	{
		cur_act->total = cur_act->ra + cur_act->rrb;
		cur_act->mode = 3;
	}
	if (cur_act->total > cur_act->rra + cur_act->rb)
	{
		cur_act->total = cur_act->rra + cur_act->rb;
		cur_act->mode = 4;
	}
}

//Find the best action to move elements from stack b to stack a
void	find_best_action(t_lst **a_stk, t_lst **b_stk,
	t_actions *min_quant_actions)
{
	int			index;
	t_lst		*tmp;
	t_actions	cur_act;

	index = 0;
	tmp = *b_stk;
	min_quant_actions->total = INT_MAX;
	while (tmp)
	{
		cur_act.ra = find_best_place_in_a(*a_stk, tmp);
		cur_act.rb = index;
		cur_act.rra = ft_listsize(*a_stk) - cur_act.ra;
		cur_act.rrb = ft_listsize(*b_stk) - cur_act.rb;
		find_best_mode(&cur_act);
		if (cur_act.total < min_quant_actions->total)
			overwritte_actions(min_quant_actions, &cur_act);
		index++;
		tmp = tmp->next;
	}
}
