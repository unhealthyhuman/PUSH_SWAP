/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:26:21 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/18 15:49:42 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	invalid_char_checker(char **input, t_node *list)
{
	int	i;
	int	j;

	i = 0;
	while (input[i] != NULL)
	{
		j = 0;
		if (input[i][0] == '\0')
			error_handler(list);
		if (input[i][0] == '-')
			j++;
		if (input[i][j] == '0' && input[i][j + 1] == '0')
			error_handler(list);
		while (input[i][j])
		{
			if (input[i][j] > '9' || input[i][j] < '0')
				error_handler(list);
			j++;
		}
		i++;
	}
}

void	rrotate(t_node **stack, int option)
{
	t_node	*penultimate;
	t_node	*last;

	if (!stack)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
	{
		if (last->next && last->next->next == NULL)
			penultimate = last;
		last = last->next;
	}
	last->next = (*stack);
	penultimate->next = NULL;
	*stack = last;
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
