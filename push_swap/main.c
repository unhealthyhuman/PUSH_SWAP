/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:21:51 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 19:23:30 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit(int num)
{
	int	i;

	i = 0;
	while ((num >> i) != 0)
	{
		i++;
	}
	return (i);
}


int	main(int argc, char **argv)
{
	t_data	data;
	t_node	*lista;
	t_node	*listb;
	
	lista = NULL;
	listb = NULL;
	if (argc > 1)
	{
		data.input = make_it_digestible(argc, argv, &data);
		vibe_check(data.input[0], &data);
		lista = ft_lstnew_pushswap(data.stack_element);
		if (!lista)
			return (0);
		digestive_process(data.input, &data, &lista);
	}
}

	/* t_node *to_delete;
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
	return (0); */