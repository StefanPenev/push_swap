/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:12:08 by stefan            #+#    #+#             */
/*   Updated: 2024/07/26 15:13:20 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act)
{
	while (min_quan_act.ra && min_quan_act.rb)
	{
		rotate_both(a_stk, b_stk);
		min_quan_act.ra--;
		min_quan_act.rb--;
	}
	while (min_quan_act.ra)
	{
		rotate_stack(a_stk, 'a');
		min_quan_act.ra--;
	}
	while (min_quan_act.rb)
	{
		rotate_stack(b_stk, 'b');
		min_quan_act.rb--;
	}
}

void	rrr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act)
{
	while (min_quan_act.rra && min_quan_act.rrb)
	{
		reverse_rotate_both(a_stk, b_stk);
		min_quan_act.rra--;
		min_quan_act.rrb--;
	}
	while (min_quan_act.rra)
	{
		reverse_rotate_stack(a_stk, 'a');
		min_quan_act.rra--;
	}
	while (min_quan_act.rrb)
	{
		reverse_rotate_stack(b_stk, 'b');
		min_quan_act.rrb--;
	}
}

void	ra_and_rrb_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act)
{
	while (min_quan_act.ra)
	{
		rotate_stack(a_stk, 'a');
		min_quan_act.ra--;
	}
	while (min_quan_act.rrb)
	{
		reverse_rotate_stack(b_stk, 'b');
		min_quan_act.rrb--;
	}
}

void	rb_and_rra_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act)
{
	while (min_quan_act.rb)
	{
		rotate_stack(b_stk, 'b');
		min_quan_act.rb--;
	}
	while (min_quan_act.rra)
	{
		reverse_rotate_stack(a_stk, 'a');
		min_quan_act.rra--;
	}
}
