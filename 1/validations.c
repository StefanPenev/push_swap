/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:54:37 by spenev            #+#    #+#             */
/*   Updated: 2024/06/27 12:25:26 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initHashSet(t_hash_set *set, int size)
{
	set->size = size;
	set->table = (struct Node**)malloc(size * sizeof(struct Node*));
	for (int i = 0; i < size; ++i)
	{
		set->table[i] = NULL;
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

	index = hash(key, set->size);
	current = set->table[index];
	while (current != NULL)
	{
		if (current->key == key)
		{
			return (0);
		}
		current = current->next;
	}
	t_node	newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = set->table[index];
    set->table[index] = newNode;

	return (1);
}

int	is_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	validate_arguments(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	int size = argc - 1;
	struct HashSet set;
	initHashSet(&set, size);

    for (int i = 1; i < argc; ++i) {
        
        if (!is_number(argv[i])) {
            ft_error();
        }

        long num = atol(argv[i]);
        if (num < -2147483648 || num > 2147483647)
            printf("Error: int value.\n");
        if (!insert(&set, num)) {
            printf("Error\n");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < set.size; ++i) {
        struct Node* current = set.table[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(set.table);

    return (EXIT_SUCCESS);
}
