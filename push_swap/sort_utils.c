/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:37:00 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/15 19:56:34 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit (1);
}
//remember to protect

int	comparer(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

int	am_i_sorted(t_node *list)
{
	t_node	*to_compare;

	to_compare = list->next;
	while (list && to_compare)
	{
		while (to_compare)
		{
			if (comparer(list->content, to_compare->content) == 1)
				return (1);
			to_compare = to_compare->next;
		}
		to_compare = list->next;
		list = list->next;
	}
	return (0);
}

void	set_r_values(t_node *list)
{
	t_node	*next1;
	t_node	*tmp;
	int		i;

	tmp = list;
	next1 = list->next;
	i = 0;
	while (list && next1)
	{
		list->r_value = i;
		while (next1)
		{
			if (list->content > next1->content)
			{
				i++;
				list->r_value = i;
			}
			next1 = next1->next;
		}
		i = 0;
		next1 = tmp;
		list = list->next;
	}
}

void	free_list(t_node *list)
{
	t_node	*to_delete;

	to_delete = list;
	while (list)
	{
		to_delete = list;
		list = list->next;
		free(to_delete);
	}
}
