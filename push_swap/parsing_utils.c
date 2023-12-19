/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:19:47 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/19 11:55:25 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vibe_check(char *vibe, t_data *data, t_node *list)
{
	data->overflow = 0;
	data->stack_element = ft_atoi(vibe, &data->overflow);
	if (data->overflow == 1)
		error_handler(list);
}

char	**make_it_digestible(char **argv, t_node *list)
{
	if (!argv[1])
		error_handler(list);
	return (argv + 1);
}

int	digestive_process(char **input_array, t_data *data, t_node **lst_start)
{
	t_node	*new;
	int		i;

	i = 1;
	while (input_array[i] != NULL)
	{
		vibe_check(input_array[i], data, *lst_start);
		new = ft_lstnew_pushswap(data->stack_element);
		if (new == NULL)
			return (1);
		ft_lstadd_back_pushswap(lst_start, new);
		i++;
	}
	if (duplicate_checker(*lst_start) == 1)
	{
		free_list(*lst_start);
		ft_printf("ERROR");
		exit (1);
	}
	return (0);
}

int	check_value(int value, t_node *list)
{
	int	next_value;

	list = list->next;
	while (list)
	{
		next_value = list->content;
		if (value == next_value)
			return (1);
		list = list->next;
	}
	return (0);
}

int	duplicate_checker(t_node *lista)
{
	int	value;

	value = 0;
	while (lista->next)
	{
		value = lista->content;
		if (check_value(value, lista) == 1)
			return (1);
		lista = lista->next;
	}
	return (0);
}
	// if (argc == 2)
	// {
	// 	if (argv[1][0] == '\0')
	// 		error_handler();
	// 	data->s_array = ft_split(argv[1], ' ');
	// 	if (data->s_array == NULL)
	// 		error_handler();
	// 	return (data->s_array);
	// }