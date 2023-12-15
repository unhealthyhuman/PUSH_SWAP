/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:51:25 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/15 19:52:58 by ischmutz         ###   ########.fr       */
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
		ft_printf("sa\n");
	if (option == 2)
		ft_printf("sb\n");
}

void	swap2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		swap(stack_a, 1);
		swap(stack_b, 2);
	}
	ft_printf("ss\n");
}

void	push(t_node **stack_dst, t_node **stack_src, int option)
{
	t_node	*push_e;

	push_e = *stack_src;
	if (push_e == NULL)
		return ;
	*stack_src = (*stack_src)->next;
	push_e->next = *stack_dst;
	*stack_dst = push_e;
	if (option == 1)
		ft_printf("pa\n");
	else if (option == 2)
		ft_printf("pb\n");
}

void	rotate(t_node **stack, int option)
{
	t_node	*last;
	t_node	*new_last;

	if (!stack)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	new_last = *stack;
	*stack = (*stack)->next;
	new_last->next = NULL;
	last->next = new_last;
	if (option == 1)
		ft_printf("ra\n");
	if (option == 2)
		ft_printf("rb\n");
}

void	rotate2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		rotate(&stack_a, 1);
		rotate(&stack_b, 2);
	}
	ft_printf("rr\n");
}

/* void	push(t_node **stack_dst, t_node **stack_src, int option)
{
	t_node	*new;
	t_node	*delete;
	int		tmp;
	
	if (!*stack_src)
		return ;
	tmp = (*stack_src)->content;
	new = ft_lstnew_pushswap(tmp);
	//protect it
	ft_lstadd_front_pushswap(stack_dst, new);
	delete = *stack_src;
	*stack_src = delete->next;
	free(delete);
	if (option == 1)
		ft_printf("pa\n");
	if (option == 2)
		ft_printf("pb\n");
} */