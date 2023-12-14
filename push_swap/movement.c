/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:51:25 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 11:37:17 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack, int option)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
	if (option == 1)
		ft_printf("sa");
	if (option == 2)
		ft_printf("sb");
}

void	swap2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		swap(stack_a, 1);
		swap(stack_b, 2);
	}
	ft_printf("ss");
}

void	push(t_node **stack_dst, t_node *stack_src, int option)
{
	if (!stack_src)
		return ;
	ft_lstadd_front_pushswap(stack_dst, stack_src);
	if (option == 1)
		ft_printf("pa");
	if (option == 2)
		ft_printf("pb");
}

void	rotate(t_node **stack, int option)
{
	t_node	*to_delete;
	t_node	*new_last;
	int		tmp;

	if (!stack)
		return ;
	to_delete = *stack;
	tmp = (*stack)->content;
	*stack = (*stack)->next;
	free(to_delete);
	new_last = ft_lstnew_pushswap(tmp);
	ft_lstadd_back_pushswap(stack, new_last);
	if (option == 1)
		ft_printf("ra");
	if (option == 2)
		ft_printf("rb");
}

void	rotate2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		rotate(&stack_a, 1);
		rotate(&stack_b, 2);
	}
	ft_printf("rr");
}
