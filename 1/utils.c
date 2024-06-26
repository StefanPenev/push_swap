#include "push_swap.h"

int     ft_isspace(int c)
 {
     return ((c >= 9 && c <= 13) || c == ' ');
 }

void	ft_error()
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}