/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:57 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/12 18:47:40 by ischmutz         ###   ########.fr       */
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

//sa : swap a - swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements).

//sb : swap b - swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements).

//ss : sa and sb at the same time.