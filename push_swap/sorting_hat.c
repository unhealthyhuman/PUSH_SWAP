/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:05:10 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 13:16:07 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stupid2(t_node *stack)
{
	if (am_i_sorted(stack) == 0)
		return ;
	ft_printf("sa");
}

void	stupid3(t_node *stack)
{
	if (am_i_sorted(stack) == 0)
		return ;
	set_relative_values(stack);
	if (stack->relative_value == 0 && stack->next->relative_value == 2)
	{
		rrotate(&stack, 1);
		swap(stack, 1);
	}
	else if (stack->relative_value == 1 && stack->next->relative_value == 0)
		swap(stack, 1);
	else if (stack->relative_value == 1 && stack->next->relative_value == 2)
		rrotate(&stack, 1);
	else if (stack->relative_value == 2 && stack->next->relative_value == 0)
		rotate(&stack, 1);
	else if (stack->relative_value == 2 && stack->next->relative_value == 1)
	{
		rrotate(&stack, 1);
		rrotate(&stack, 1);
	}
}

void	stupid4(t_node *stacka, t_node *stackb)
{
	t_node *tmp;

	tmp = stacka;
	if (am_i_sorted(stacka) == 0)
		return ;
	set_relative_values(stacka);
	while (stacka->next)
	{
		if (stacka->relative_value == 0)
			push(&stackb, stacka, 2);
		stacka = stacka->next;
	}
	stacka = tmp;
	stupid3(stacka);
	push(&stacka, stackb, 1);
}