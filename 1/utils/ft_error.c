#include "../push_swap.h"

void	ft_error_set(t_hash_set set)
{
	ft_putstr_fd("Error\n", 1);
	free_hash_set(&set);
	exit(EXIT_FAILURE);
}

void	ft_error()
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}