/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:59:05 by spenev            #+#    #+#             */
/*   Updated: 2024/08/08 23:50:49 by stefan           ###   ########.fr       */
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
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
	int	mode;	
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
void	free_list(t_lst *head);
int		ft_listsize(t_lst *lst);
t_lst	*ft_lst_new(int content);
void	ft_listadd_back(t_lst **lst, t_lst *new);
void	ft_listadd_front(t_lst **lst, t_lst *new);

// args utils
void	ft_free(char **values);

// error
void	ft_error(void);
void	ft_error_set(t_hash_set	set, char **values);

// sort
void	mini_sort(t_lst **stack);
void	initial_sort(t_lst **a_stk, t_lst **b_stk);

// sort utils
int		is_stack_sorted(t_lst *stack);
int		get_max_value_index(t_lst *lst);
int		get_median_value(t_lst *stack_a, int len);

// find
void	find_best_action(t_lst **a_stk, t_lst **b_stk,
			t_actions *min_quant_actions);

// modes
void	rr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions);
void	rrr_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions);
void	ra_and_rrb_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions);
void	rb_and_rra_mode(t_lst **a_stk, t_lst **b_stk, t_actions min_actions);

// validations
long	ft_atol(const char *str);
int		is_number(const char *str);
void	free_hash_set(t_hash_set *set);
int		validate_arguments(int argc, char *argv[]);

// Push Swap
void	push_swap(int argc, char *argv[]);

#endif