/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:51:25 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/12 21:09:24 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
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
}

void	swap2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{	
		swap(stack_a);
		swap(stack_b);
	}
}

void	push(t_node **stack_dst, t_node *stack_src)
{
	if (!stack_src)
		return ;
	ft_lstadd_front_pushswap(stack_dst, stack_src);
}
void	rotate(t_node **stack)
{
	if(!stack)
		return ;
	t_node	*to_delete;
	t_node	*new_last;
	int		tmp;
	
	to_delete = *stack;
	tmp = (*stack)->content;
	*stack = (*stack)->next;
	free(to_delete);
	new_last = ft_lstnew_pushswap(tmp);
	ft_lstadd_back_pushswap(stack, new_last);
}
void	rotate2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		rotate(&stack_a);
		rotate(&stack_b);
	}
}

void	rrotate(t_node **stack)
{
	t_node	*to_delete;
	t_node	*new_beginning;
	int		tmp;
	t_node	*penultimate;
	t_node	*last;
	
	if(!stack)
		return ;
	if(*stack == NULL || (*stack)->next == NULL)
		return ;
	penultimate = *stack;
	last = penultimate->next;
	while (last->next)
	{
		penultimate = penultimate->next;
		last = last->next;
	}
	to_delete = ft_lstlast_pushswap(*stack);
	tmp = to_delete->content;
	free(to_delete);
	penultimate->next = NULL;
	new_beginning = ft_lstnew_pushswap(tmp);
	ft_lstadd_front_pushswap(stack, new_beginning);
}

void	rrotate2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		rrotate(&stack_a);
		rrotate(&stack_b);
	}
}