/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:54:37 by spenev            #+#    #+#             */
/*   Updated: 2024/06/28 23:47:45 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_hash_set(t_hash_set *set, int size)
{
	int	i;

	set->size = size;
	set->table = (t_node **)malloc(size * sizeof(t_node *));
	i = 0;
	while (i < size)
	{
		set->table[i] = NULL;
		i++;
	}
}

int	hash(int key, int size)
{
	return (key % size);
}

int	insert(t_hash_set *set, int key)
{
	int		index;
	t_node	*current;
	t_node	*new_node;

	index = hash(key, set->size);
	current = set->table[index];
	while (current != NULL)
	{
		if (current->key == key)
			return (0);
		current = current->next;
	}
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->key = key;
	new_node->next = set->table[index];
	set->table[index] = new_node;
	return (1);
}

void	free_hash_set(t_hash_set *set)
{
	t_node	*current;
	t_node	*temp;
	int		i;

	i = 0;
	while (i < set->size)
	{
		current = set->table[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		i++;
	}
	free(set->table);
}

int	validate_arguments(int argc, char *argv[])
{
	t_hash_set	set;
	int			size;
	int			i;
	long		num;

	if (argc <= 1)
		ft_error(set);
	size = argc - 1;
	init_hash_set(&set, size);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			ft_error(set);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error(set);
		if (!insert(&set, num))
			ft_error(set);
		i++;
	}
	free_hash_set(&set);
	return (EXIT_SUCCESS);
}
