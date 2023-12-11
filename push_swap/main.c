/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:21:51 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/11 19:47:52 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit (1);
}

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
	return (argv);
}

t_node	digestive_process(char **input_array, t_data *data, t_node *list)
{
	int	i;

	i = 0;
	while (input_array[i] != NULL)
	{
		vibe_check(input_array[i++], &data);
		list->content = data->stack_element;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_node	list;
	
	//list.content = NULL;
	if (argc > 1)
	{
		data.input = make_it_digestible(argc, argv, &data);
		digestive_process(data.input, &data, &list);
	
	}
	return (0);
}
