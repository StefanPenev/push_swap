/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:41:33 by spenev            #+#    #+#             */
/*   Updated: 2024/07/25 11:43:34 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa, sb
void	swap_stack(t_lst **stack, char stk_name)
{
	t_lst	*tmp;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
	if (stk_name == 'a')
		ft_putendl_fd("sa", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("sb", 1);
}

//ra, rb
void	rotate_stack(t_lst **stack, char stk_name)
{
	t_lst	*tmp;
	t_lst	*new_head;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		new_head = (*stack)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		(*stack)->next = NULL;
		*stack = new_head;
	}
	if (stk_name == 'a')
		ft_putendl_fd("ra", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("rb", 1);
}

//rra, rrb
void	reverse_rotate_stack(t_lst **stack, char stk_name)
{
	t_lst	*tmp;
	t_lst	*current;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		current = *stack;
		while (current->next != NULL)
		{
			tmp = current;
			current = current->next;
		}
		tmp->next = NULL;
		current->next = *stack;
		*stack = current;
	}
	if (stk_name == 'a')
		ft_putendl_fd("rra", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("rrb", 1);
}

//pa, pb
void	push(t_lst **to, t_lst **from, char stk_name)
{
	t_lst	*tmp;

	if ((*from) != NULL)
	{
		tmp = *from;
		*from = (*from)->next;
		ft_listadd_front(to, tmp);
	}
	if (stk_name == 'a')
		ft_putendl_fd("pa", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("pb", 1);
}
