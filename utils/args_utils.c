/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:39:11 by spenev            #+#    #+#             */
/*   Updated: 2024/08/09 08:55:08 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Check if the provided argument is a number
int	is_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit((int)*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

//Check if the provided character is a whitespace character
int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

//Convert an ASCII string to a long integer
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
		if (*(str + 1) == '\0')
			ft_putstr_fd("Error\n", 2);
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

//Free
void	ft_free(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}
