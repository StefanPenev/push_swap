#include "push_swap.h"

// void	init_stack(t_lst **stack_a, int argc, char *argv[])
// {
// 	int num;
// 	int	i;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		num = ft_atoi(argv[i]);
// 		ft_listadd_back(stack_a, ft_lst_new(num));
// 		i++;
// 	}
// }

// void push_swap(int argc, char *argv[])
// {
// 	t_lst *stack_a;
// 	t_lst *stack_b;

//     stack_a = NULL;
//    	stack_b = NULL;
//     validate_arguments(argc, argv);
//     init_stack(&stack_a, argc, argv);
//     if (argc == 4)
//     {
//         mini_sort(&stack_a);
//         exit(EXIT_SUCCESS);
//     }
//     if (is_stack_sorted(stack_a))
// 		exit(EXIT_SUCCESS);	
// 	initial_sort(&stack_a, &stack_b);
// }


static int	positive_or_negative(char in, int sign)
{
	if (in == 45)
		sign = -sign;
	return (sign);
}

int	ft_atoi_only_for_num(const char *str)
{
	int		in;
	int		sign;
	long	num;

	in = 0;
	sign = 1;
	num = 0;
	while ((((str[in] > 8) && (str[in] < 14)) || str[in] == 32) && \
			str[in] != '\0')
		in++;
	if (str[in] == 43 || str[in] == 45)
		sign = positive_or_negative(str[in++], sign);
	while (str[in])
	{
		if (str[in] < 48 || str[in] > 57)
			ft_error();
		num = num * 10 + (str[in] - '0');
		in++;
	}
	num = num * sign;
	if (num > 2147483647 || num < -2147483648)
		ft_error();
	return ((int)num);
}


void	duplicate_checker(t_lst *stack)
{
	t_lst	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				ft_error();
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void	argv_processing(t_lst **a_stk, char **argv, int len)
{
	int		val;
	int		it;
	int		num;
	char	**sump;

	val = 1;
	while (val <= len)
	{
		it = 0;
		sump = ft_split(argv[val], ' ');
		if (!sump)
			ft_error();
		while (sump[it])
		{
			num = ft_atoi_only_for_num(sump[it]);
			ft_listadd_back(a_stk, ft_lst_new(num));
			free(sump[it]);
			it++;
		}
		free(sump);
		val++;
	}
}

void	push_swap(int argc, char **argv)
{
	int		len;
	t_lst	*a_stk;
	t_lst	*b_stk;

	a_stk = NULL;
	b_stk = NULL;
	// if (argc == 1)
	// 	ft_prompt("No arguments");
	len = argc - 1;
	argv_processing(&a_stk, argv, len);
	duplicate_checker(a_stk);
	initial_sort(&a_stk, &b_stk);
}