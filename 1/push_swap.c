#include "push_swap.h"

void	init_stack(t_lst **stack_a, int argc, char *argv[])
{
	int num;
	int	i;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_listadd_back(stack_a, ft_lst_new(num));
		i++;
	}
}

void push_swap(int argc, char *argv[])
{
	t_lst *stack_a;
	t_lst *stack_b;

    stack_a = NULL;
   	stack_b = NULL;
    validate_arguments(argc, argv);
    init_stack(&stack_a, argc, argv);
    if (argc == 4)
    {
        mini_sort(&stack_a);
        exit(EXIT_SUCCESS);
    }
    if (is_stack_sorted(stack_a))
		exit(EXIT_SUCCESS);	
	initial_sort(&stack_a, &stack_b);

	// while(stack_a)
	// {
	// 	printf("%d\n", stack_a->value);
	// 	stack_a = stack_a->next;
	// }
}
