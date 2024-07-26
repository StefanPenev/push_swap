/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:59:47 by stefan            #+#    #+#             */
/*   Updated: 2024/07/26 15:06:05 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_lst **stack_a, int argc, char *argv[])
{
	int	num;
	int	i;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_listadd_back(stack_a, ft_lst_new(num));
		i++;
	}
}

void	push_swap(int argc, char *argv[])
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	validate_arguments(argc, argv);
	init_stack(&stack_a, argc, argv);
	if (argc == 4)
	{
		mini_sort(&stack_a);
		free_list(stack_a);
		exit(EXIT_SUCCESS);
	}
	if (is_stack_sorted(stack_a))
	{
		free_list(stack_a);
		exit(EXIT_SUCCESS);
	}
	initial_sort(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
}
