/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:22:20 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/18 15:51:31 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				content;
	int				r_value;
}	t_node;

typedef struct s_data
{
	int		overflow;
	int		i;
	int		stack_element;
	int		size;
	int		max_r_value;
	int		max_bit_value;
	int		j;
	int		k;
	int		argc;
	char	**s_array;
	char	**input;
}	t_data;

t_node	*ft_lstnew_pushswap(int content);
t_node	*ft_lstlast_pushswap(t_node *lst);
void	ft_lstadd_front_pushswap(t_node **lst, t_node *new);
void	ft_lstadd_back_pushswap(t_node **lst, t_node *new);
int		ft_lstsize_pushswap(t_node *lst);
void	vibe_check(char *vibe, t_data *data, t_node *list);
char	**make_it_digestible(char **argv, t_node *list);
int		digestive_process(char **input_array, t_data *data, t_node **lst_start);
int		check_value(int value, t_node *lista);
int		duplicate_checker(t_node *lista);
void	invalid_char_checker(char **input, t_node *list);
void	swap(t_node *stack, int option);
void	swap2(t_node *stack_a, t_node *stack_b);
void	push(t_node **stack_dst, t_node **stack_src, int option);
void	rotate(t_node **stack, int option);
void	rotate2(t_node *stack_a, t_node *stack_b);
void	rrotate(t_node **stack, int option);
void	rrotate2(t_node *stack_a, t_node *stack_b);
void	error_handler(t_node *list);
int		comparer(int a, int b);
int		am_i_sorted(t_node *list);
void	set_r_values(t_node *list);
void	free_list(t_node *list);
void	sort_2(t_node **stack);
void	sort_3(t_node **stack);
void	sort_4(t_node **stacka, t_node **stackb);
void	sort_5(t_node **stacka, t_node **stackb);
int		max_bit(int num);
void	tiny_stack(t_node **lista, t_node **listb, t_data *data);
void	big_stack(t_node **lista, t_node **listb, t_data *data);
void	sort_big_stack(t_node **lista, t_node **listb, t_data *data);

#endif