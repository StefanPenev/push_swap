/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:12:08 by stefan            #+#    #+#             */
/*   Updated: 2024/07/27 00:24:47 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates simultaneous or individual the two stacks based 
on the number of actions specified in min_actions. */
void	rr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions)
{
	while (min_actions.ra && min_actions.rb)
	{
		rotate_both(a_stk, b_stk);
		min_actions.ra--;
		min_actions.rb--;
	}
	while (min_actions.ra)
	{
		rotate_stack(a_stk, 'a');
		min_actions.ra--;
	}
	while (min_actions.rb)
	{
		rotate_stack(b_stk, 'b');
		min_actions.rb--;
	}
}

/* Reverse rotates simultaneous or individual the two stacks based 
on the number of actions specified in min_actions. */
void	rrr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions)
{
	while (min_actions.rra && min_actions.rrb)
	{
		reverse_rotate_both(a_stk, b_stk);
		min_actions.rra--;
		min_actions.rrb--;
	}
	while (min_actions.rra)
	{
		reverse_rotate_stack(a_stk, 'a');
		min_actions.rra--;
	}
	while (min_actions.rrb)
	{
		reverse_rotate_stack(b_stk, 'b');
		min_actions.rrb--;
	}
}

/* Reverse rotate stack b and rotate stack a based 
on the number of actions specified in min_actions. */
void	ra_and_rrb_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions)
{
	while (min_actions.ra)
	{
		rotate_stack(a_stk, 'a');
		min_actions.ra--;
	}
	while (min_actions.rrb)
	{
		reverse_rotate_stack(b_stk, 'b');
		min_actions.rrb--;
	}
}

/* Reverse rotate stack a and rotate stack b based 
on the number of actions specified in min_actions. */
void	rb_and_rra_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions)
{
	while (min_actions.rb)
	{
		rotate_stack(b_stk, 'b');
		min_actions.rb--;
	}
	while (min_actions.rra)
	{
		reverse_rotate_stack(a_stk, 'a');
		min_actions.rra--;
	}
}
