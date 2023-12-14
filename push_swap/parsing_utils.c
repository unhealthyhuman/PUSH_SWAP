/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:19:47 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 19:20:05 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vibe_check(char *vibe, t_data *data)
{
	data->overflow = 0;
	data->stack_element = ft_atoi(vibe, &data->overflow);
	if (data->overflow == 1)
		error_handler();
}

char	**make_it_digestible(int argc, char **argv, t_data *data)
{
	data->i = 1;
	
	if (argc == 2)
	{
		data->s_array = ft_split(argv[1], ' ');
		return (data->s_array);
	}
	return (argv + 1);
}

int	digestive_process(char **input_array, t_data *data, t_node **beginning_lst)
{
	t_node	*new;
	int	i;

	i = 1;
	while (input_array[i] != NULL)
	{
		vibe_check(input_array[i], data);
		new = ft_lstnew_pushswap(data->stack_element);
		if (new == NULL)
			return (1);
		ft_lstadd_back_pushswap(beginning_lst, new);
		i++;
	}
	return (0);
}
