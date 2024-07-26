/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:15:36 by stefan            #+#    #+#             */
/*   Updated: 2024/07/27 00:01:42 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Hash set errors.
Free the allocated memory for the hash set. */
void	ft_error_set(t_hash_set set)
{
	ft_putstr_fd("Error\n", 1);
	free_hash_set(&set);
	exit(EXIT_FAILURE);
}

//Handle general validation errors.
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}
