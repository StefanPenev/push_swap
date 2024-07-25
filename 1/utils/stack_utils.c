#include "../push_swap.h"

//Adds a node at the beginning of the stack
void	ft_listadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

//Adds a node at the end of the stack
void	ft_listadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*temp;

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

//Create new node
t_lst	*ft_lst_new(int content)
{
	t_lst	*list;

	list = (t_lst *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->value = content;
	list->next = NULL;
	return (list);
}

//Get the size of the stack
int	ft_listsize(t_lst *lst)
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