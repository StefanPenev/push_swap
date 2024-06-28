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

void	init_stack(a_list **stack_a, int argc, char *argv[])
{
	int	i;
	int	num;

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

int	get_max_value_index(a_list *lst)
{
	int	max_value;
	int	max_ind;
	int	i;

	max_ind = 0;
	max_value = lst->content;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (lst->content > max_value)
		{
			max_ind = i;
			max_value = lst->content;
		}
		lst = lst->next;
		i++;
	}
	return (max_ind);
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


void push_swap(int argc, char *argv[])
{
	//a_list *stack_a;
	//a_list *stack_b;

    //stack_a = NULL;
    //stack_b = NULL;
    validate_arguments(argc, argv);
    //init_stack(&stack_a, argc, argv);
    // if (argc == 4)
    // {
    //     mini_sort(&stack_a);
    //     exit(EXIT_SUCCESS);
    // }
    // if (is_stack_sorted(stack_a))
    //     exit(EXIT_SUCCESS);
}
