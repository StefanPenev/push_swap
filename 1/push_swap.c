#include "push_swap.h"

a_list	*ft_lst_new(int content)
{
	a_list	*list;

	list = (a_list *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_backk(a_list **lst, a_list *new)
{
	a_list	*temp;

	if (lst && new)
	{
		if (*lst == NULL)
		{
			*lst = new;
			return ;
		}
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void init_stack(a_list **stack_a, int argc, char *argv[])
{
    int i;
    int num;

    if (argc == 2)
    {
        
    }
    
    i = 1;
    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        ft_lstadd_backk(stack_a, ft_lst_new(num));
        i++;
    }
}

void	ft_lstadd_frontt(a_list **lst, a_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstfind_ind_of_max_value(a_list *lst)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = lst->content;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if (lst->content > max_value)
		{
			max_ind = it;
			max_value = lst->content;
		}
		lst = lst->next;
		it++;
	}
	return (max_ind);
}

void	swap_stk(a_list **stack, char stk_name)
{
	a_list	*tmp;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
	if (stk_name == 'a')
		ft_putendl_fd("sa", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("sb", 1);
}

void	rotate_stk(a_list **stack, char stk_name)
{
	a_list	*tmp;
	a_list	*new_head;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		new_head = (*stack)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		(*stack)->next = NULL;
		*stack = new_head;
	}
	if (stk_name == 'a')
		ft_putendl_fd("ra", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("rb", 1);
}

void	rev_rotate_stk(a_list **stack, char stk_name)
{
	a_list	*tmp;
	a_list	*current;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		current = *stack;
		while (current->next != NULL)
		{
			tmp = current;
			current = current->next;
		}
		tmp->next = NULL;
		current->next = *stack;
		*stack = current;
	}
	if (stk_name == 'a')
		ft_putendl_fd("rra", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("rrb", 1);
}

void	push_on_stk(a_list **to, a_list **from, char stk_name)
{
	a_list	*tmp;

	if ((*from) != NULL)
	{
		tmp = *from;
		*from = (*from)->next;
		ft_lstadd_frontt(to, tmp);
	}
	if (stk_name == 'a')
		ft_putendl_fd("pa", 1);
	else if (stk_name == 'b')
		ft_putendl_fd("pb", 1);
}


int	ft_lstsizee(a_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	small_sort(a_list **stack)
{
	int	max_index;

	if (ft_lstsizee(*stack) == 2 && (*stack)->content > (*stack)->next->content)
		swap_stk(stack, 'a');
	else
	{
		max_index = ft_lstfind_ind_of_max_value(*stack);
		if (max_index == 0)
			rotate_stk(stack, 'a');
		else if (max_index == 1)
			rev_rotate_stk(stack, 'a');
		if ((*stack)->content > (*stack)->next->content)
			swap_stk(stack, 'a');
	}
}

void push_swap(int argc, char *argv[])
{
    a_list *stack_a;
    a_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    validate_arguments(argc, argv);
    init_stack(&stack_a, argc, argv);
    if (argc == 4)
    {
        small_sort(&stack_a);
        exit(EXIT_SUCCESS);
    }
    if (is_stack_sorted(stack_a))
        exit(EXIT_SUCCESS);
    bucket_sort(&stack_a, &stack_b);    
}