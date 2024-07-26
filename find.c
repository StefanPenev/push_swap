/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:24:44 by stefan            #+#    #+#             */
/*   Updated: 2024/07/26 15:26:04 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	overwriting_values(t_actions *min_quan_act, t_actions *cur_act)
{
	min_quan_act->ra = cur_act->ra;
	min_quan_act->rb = cur_act->rb;
	min_quan_act->rra = cur_act->rra;
	min_quan_act->rrb = cur_act->rrb;
	min_quan_act->total = cur_act->total;
	min_quan_act->mode = cur_act->mode;
}

int	find_best_place_in_a(t_lst *a_stk, t_lst *b_stk)
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

void	find_best_mode(t_actions *cur_act)
{
	cur_act->total = INT_MAX;
	if (cur_act->total > ft_find_max(cur_act->ra, cur_act->rb))
	{
		cur_act->total = ft_find_max(cur_act->ra, cur_act->rb);
		cur_act->mode = 1;
	}
	if (cur_act->total > ft_find_max(cur_act->rra, cur_act->rrb))
	{
		cur_act->total = ft_find_max(cur_act->rra, cur_act->rrb);
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
			overwriting_values(min_quant_actions, &cur_act);
		index++;
		tmp = tmp->next;
	}
}
