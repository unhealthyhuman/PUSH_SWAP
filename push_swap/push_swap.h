/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:22:20 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 19:23:00 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				content;
	int				relative_value;
}	t_node;

typedef struct s_data
{
	int		overflow;
	int		i;
	int		stack_element;
	char	**s_array;
	char	**input;
}	t_data;

t_node	*ft_lstnew_pushswap(int content);
t_node	*ft_lstlast_pushswap(t_node *lst);
void	ft_lstadd_front_pushswap(t_node **lst, t_node *new);
void	ft_lstadd_back_pushswap(t_node **lst, t_node *new);
int		ft_lstsize_pushswap(t_node *lst);
void	vibe_check(char *vibe, t_data *data);
char	**make_it_digestible(int argc, char **argv, t_data *data);
int		digestive_process(char **input_array, t_data *data, t_node **beginning_lst);
void	swap(t_node *stack, int option);
void	swap2(t_node *stack_a, t_node *stack_b);
void	push(t_node **stack_dst, t_node **stack_src, int option);
void	rotate(t_node **stack, int option);
void	rotate2(t_node *stack_a, t_node *stack_b);
void	rrotate(t_node **stack, int option);
void	rrotate2(t_node *stack_a, t_node *stack_b);
void	error_handler(void);
int		comparer(int a, int b);
int		am_i_sorted(t_node *list);
void	set_relative_values(t_node *list);
void	sort_3(t_node *stack);
void	sort_4(t_node **stacka, t_node **stackb);
void	sort_5(t_node **stacka, t_node **stackb);
int		max_bit(int num);

#endif