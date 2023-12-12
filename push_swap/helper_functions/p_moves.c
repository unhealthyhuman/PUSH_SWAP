/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:03:45 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/12 18:49:00 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_dst, t_node *stack_src)
{
	if (!stack_src)
		return ;
	ft_lstadd_front_pushswap(stack_dst, stack_src);
}

//pa : push a - take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.

//pb : push b - take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.