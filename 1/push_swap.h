#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct v_list
{
	int			    content;
	struct v_list	*next;
}	                a_list;

int validate_arguments(int argc, char *argv[]);
long	ft_atol(const char *str);
void	ft_error();
void push_swap(int argc, char *argv[]);
int is_stack_sorted(a_list *stack);
//void sort_stack(a_list **stack_a, a_list **stack_b);
//void quick_sort(a_list **a, a_list **b);
//void merge_sort(a_list **a, a_list **b);
//void insertion_sort(a_list **a, a_list **b);
void bucket_sort(a_list **a, a_list **b);
//void radix_sort(a_list **a, a_list **b);
#endif