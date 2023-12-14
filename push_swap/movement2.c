/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:26:21 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 14:20:45 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_node **stack, int option)
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
	if (option == 1)
		ft_printf("rra\n");
	if (option == 2)
		ft_printf("rrb\n");
}

void	rrotate2(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_b)
	{
		rrotate(&stack_a, 1);
		rrotate(&stack_b, 2);
	}
	ft_printf("rrr\n");
}
