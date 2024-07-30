/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:59:47 by stefan            #+#    #+#             */
/*   Updated: 2024/07/30 10:53:21 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Initialize the stack.
static	void	init_stack(t_lst **stack_a, int argc, char *argv[])
{
	int	num;
	int	i;

	i = 0;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_listadd_back(stack_a, ft_lst_new(num));
		i++;
	}
}

int	count_nums(char **values)
{
	int i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}

// void print(char **n)
// {
// 	int i = 0;
// 	while (n[i])
// 	{
// 		printf("%s\n", n[i]);
// 		i++;
// 	}
// }

void	push_swap(int argc, char *argv[])
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	char **values;
    int count;

	stack_a = NULL;
	stack_b = NULL;
	count = 0;
	if (argc == 2) {
        values = ft_split(argv[1], ' ');
		count = count_nums(values);
    } else {
        values = argv + 1;
        count = argc - 1;
    }
	validate_arguments(count, values);
	init_stack(&stack_a, count, values);
	if (is_stack_sorted(stack_a))
	{
		free_list(stack_a);
		exit(EXIT_SUCCESS);
	}
	if (argc == 4 || count <= 3)
	{
		mini_sort(&stack_a);
		free_list(stack_a);
		exit(EXIT_SUCCESS);
	}
	initial_sort(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
}
