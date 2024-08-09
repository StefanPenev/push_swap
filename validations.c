/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:54:37 by spenev            #+#    #+#             */
/*   Updated: 2024/08/09 08:52:07 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Initializes a hash set with a specified size.
static	void	init_hash_set(t_hash_set *set, int size)
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

//Calculates the hash value for a given key based on the table size.
static	int	hash(int key, int size)
{
	return (((key % size) + size) % size);
}

//Inserts a new key into the hash set if it is not already present.
static	int	insert(t_hash_set *set, int key)
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

//Deallocates the memory used by the hash set.
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

//Validates the command line arguments.
int	validate_arguments(int size, char **values)
{
	t_hash_set	set;
	int			i;
	long		num;

	if (size <= 0)
		ft_error(values);
	init_hash_set(&set, size);
	i = 0;
	while (values[i])
	{
		if (!is_number(values[i]))
			ft_error_set(set, values);
		num = ft_atol(values[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error_set(set, values);
		if (!insert(&set, num))
			ft_error_set(set, values);
		i++;
	}
	free_hash_set(&set);
	return (EXIT_SUCCESS);
}
