/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:21:51 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/13 17:47:39 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit (1); //before terminating process, free EVERYTHING make a f() or smt smart
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

int	main(int argc, char **argv)
{
	t_data	data;
	t_node	*lista;
	
	lista = NULL;
	if (argc > 1)
	{
		data.input = make_it_digestible(argc, argv, &data);
		vibe_check(data.input[0], &data);
		lista = ft_lstnew_pushswap(data.stack_element);
		if (!lista)
			return (0);
		digestive_process(data.input, &data, &lista);
	}
	
	t_node *to_delete;
	//check
	while(lista)
	{
		//ft_printf("Hej\n");
		to_delete = lista;
		ft_printf("%d\n", lista->content);
		lista = lista->next;
		free(to_delete);
	}
	free(lista);
	return (0);
}
