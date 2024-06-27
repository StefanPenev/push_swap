/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:59:05 by spenev            #+#    #+#             */
/*   Updated: 2024/06/27 22:14:11 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct v_list
{
	int				content;
	struct v_list	*next;
}					a_list;

typedef struct s_node
{
	int				key;
	struct s_node	*next;
}					t_node;

typedef struct s_hash_set
{
	int				size;
	struct s_node	**table;
}					t_hash_set;


// operations
void	swap_stack(a_list **stack, char stk_name);
void	rotate_stack(a_list **stack, char stk_name);
void	reverse_rotate_stack(a_list **stack, char stk_name);
void	push(a_list **to, a_list **from, char stk_name);

int		validate_arguments(int argc, char *argv[]);
long	ft_atol(const char *str);
void	ft_error(void);
void	push_swap(int argc, char *argv[]);
int		is_stack_sorted(a_list *stack);
void	mini_sort(a_list **stack);
int	ft_lstsizee(a_list *lst);
int	get_max_value_index(a_list *lst);
void	ft_lstadd_frontt(a_list **lst, a_list *new);
//void sort_stack(a_list **stack_a, a_list **stack_b);
//void quick_sort(a_list **a, a_list **b);
//void merge_sort(a_list **a, a_list **b);
//void insertion_sort(a_list **a, a_list **b);
//void bucket_sort(a_list **a, a_list **b);
//void radix_sort(a_list **a, a_list **b);

#endif