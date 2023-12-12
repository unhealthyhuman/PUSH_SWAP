/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:20 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/12 15:10:21 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew_pushswap(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front_pushswap(t_node **lst, t_node *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}

t_node	*ft_lstlast_pushswap(t_node *lst)
{
	if (!(lst))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_pushswap(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast_pushswap(*lst);
		tmp->next = new;
		new->prev = tmp;
	}
}