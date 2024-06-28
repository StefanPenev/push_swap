/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:33:09 by stefan            #+#    #+#             */
/*   Updated: 2024/06/29 00:37:29 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ss
void	swap_both(a_list **a_stk, a_list **b_stk)
{
	swap_stack(a_stk, 'n');
	swap_stack(b_stk, 'n');
	ft_putendl_fd("ss", 1);
}

//rr
void	rotate_both(a_list **a_stk, a_list **b_stk)
{
	rotate_stack(a_stk, 'n');
	rotate_stack(b_stk, 'n');
	ft_putendl_fd("rr", 1);
}

//rrr
void	reverse_rotate_both(a_list **a_stk, a_list **b_stk)
{
	reverse_rotate_stack(a_stk, 'n');
	reverse_rotate_stack(b_stk, 'n');
	ft_putendl_fd("rrr", 1);
}

