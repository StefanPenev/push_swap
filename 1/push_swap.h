/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:59:05 by spenev            #+#    #+#             */
/*   Updated: 2024/07/25 17:52:53 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;

typedef struct s_actions
{
	int ra;
	int rra;
	int rb;
	int rrb;
	int total;
	int mode;	
}		t_actions;

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
void	swap_stack(t_lst **stack, char stk_name);
void	rotate_stack(t_lst **stack, char stk_name);
void	reverse_rotate_stack(t_lst **stack, char stk_name);
void	push(t_lst **to, t_lst **from, char stk_name);
void	swap_both(t_lst **a_stk, t_lst **b_stk);
void	rotate_both(t_lst **a_stk, t_lst **b_stk);
void	reverse_rotate_both(t_lst **a_stk, t_lst **b_stk);

// stack utils
int		ft_listsize(t_lst *lst);
t_lst	*ft_lst_new(int content);
void	ft_listadd_back(t_lst **lst, t_lst *new);
void	ft_listadd_front(t_lst **lst, t_lst *new);

// error
void	ft_error();
void	ft_error_set(t_hash_set	set);

// sort
void	mini_sort(t_lst **stack);
void	initial_sort(t_lst **a_stk, t_lst **b_stk);

// sort utils
int		get_median_value(t_lst *stack_a, int len);

// find
void	find_best_action(t_lst **a_stk, t_lst **b_stk, t_actions *min_quant_actions);

// modes
void	rr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act);
void	rrr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act);
void	ra_and_rrb_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act);
void	rb_and_rra_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_quan_act);

void free_hash_set(t_hash_set *set);
int	is_number(const char *str);
int		validate_arguments(int argc, char *argv[]);
long	ft_atol(const char *str);

void	push_swap(int argc, char *argv[]);
int		is_stack_sorted(t_lst *stack);


int	get_max_value_index(t_lst *lst);

//void sort_stack(t_lst **stack_a, t_lst **stack_b);
//void quick_sort(t_lst **a, t_lst **b);
//void merge_sort(t_lst **a, t_lst **b);
//void insertion_sort(t_lst **a, t_lst **b);
//void bucket_sort(t_lst **a, t_lst **b);
//void radix_sort(t_lst **a, t_lst **b);

#endif