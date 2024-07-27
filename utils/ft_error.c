/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:08:26 by spenev            #+#    #+#             */
/*   Updated: 2024/07/27 11:08:37 by spenev           ###   ########.fr       */
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
