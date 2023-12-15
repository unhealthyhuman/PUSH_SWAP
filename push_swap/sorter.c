/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:05:10 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/15 19:56:49 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack)
{
	if (am_i_sorted(*stack) == 0)
		return ;
	swap(*stack, 1);
}

void	sort_3(t_node **stack)
{
	if (am_i_sorted(*stack) == 0)
		return ;
	set_r_values(*stack);
	if ((*stack)->r_value == 0 && (*stack)->next->r_value == 2)
	{
		rrotate(stack, 1);
		swap(*stack, 1);
	}
	else if ((*stack)->r_value == 1 && (*stack)->next->r_value == 0)
		swap((*stack), 1);
	else if ((*stack)->r_value == 1 && (*stack)->next->r_value == 2)
		rrotate(stack, 1);
	else if ((*stack)->r_value == 2 && (*stack)->next->r_value == 0)
		rotate(stack, 1);
	else if ((*stack)->r_value == 2 && (*stack)->next->r_value == 1)
	{
		rrotate(stack, 1);
		rrotate(stack, 1);
		swap(*stack, 1);
	}
}

void	sort_4(t_node **stacka, t_node **stackb)
{
	t_node	*tmp;

	tmp = *stacka;
	if (am_i_sorted(*stacka) == 0)
		return ;
	set_r_values(*stacka);
	if ((*stacka)->next->r_value == 0)
		swap(*stacka, 1);
	else if ((*stacka)->next->next->r_value == 0)
	{
		rrotate(stacka, 1);
		rrotate(stacka, 1);
	}
	else if ((*stacka)->next->next->next->r_value == 0)
	{
		rrotate(stacka, 1);
	}
	push(stackb, stacka, 2);
	sort_3(stacka);
	push(stacka, stackb, 1);
}

void	sort_5(t_node **stacka, t_node **stackb)
{
	if (am_i_sorted(*stacka) == 0)
		return ;
	set_r_values(*stacka);
	if ((*stacka)->next->r_value == 0)
		swap(*stacka, 1);
	else if ((*stacka)->next->next->r_value == 0)
	{
		rrotate(stacka, 1);
		rrotate(stacka, 1);
		rrotate(stacka, 1);
	}
	else if ((*stacka)->next->next->next->r_value == 0)
	{
		rrotate(stacka, 1);
		rrotate(stacka, 1);
	}
	else if ((*stacka)->next->next->next->next->r_value == 0)
		rrotate(stacka, 1);
	push(stackb, stacka, 2);
	sort_4(stacka, stackb);
	push(stacka, stackb, 1);
}
