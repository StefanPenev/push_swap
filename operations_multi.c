/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:14:31 by spenev            #+#    #+#             */
/*   Updated: 2024/07/27 11:14:33 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ss
void	swap_both(t_lst **a_stk, t_lst **b_stk)
{
	swap_stack(a_stk, 'n');
	swap_stack(b_stk, 'n');
	ft_putendl_fd("ss", 1);
}

//rr
void	rotate_both(t_lst **a_stk, t_lst **b_stk)
{
	rotate_stack(a_stk, 'n');
	rotate_stack(b_stk, 'n');
	ft_putendl_fd("rr", 1);
}

//rrr
void	reverse_rotate_both(t_lst **a_stk, t_lst **b_stk)
{
	reverse_rotate_stack(a_stk, 'n');
	reverse_rotate_stack(b_stk, 'n');
	ft_putendl_fd("rrr", 1);
}
