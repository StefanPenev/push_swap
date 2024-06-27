/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:51:58 by spenev            #+#    #+#             */
/*   Updated: 2024/06/27 12:07:39 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(a_list **stack)
{
	int	max_index;

	if (ft_lstsizee(*stack) == 2 && (*stack)->content > (*stack)->next->content)
		swap_stack(stack, 'a');
	else
	{
		max_index = get_max_value_index(*stack);
		if (max_index == 0)
			rotate_stack(stack, 'a');
		else if (max_index == 1)
			reverse_rotate_stack(stack, 'a');
		if ((*stack)->content > (*stack)->next->content)
			swap_stack(stack, 'a');
	}
}
