/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:21:51 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/14 21:23:51 by ischmutz         ###   ########.fr       */
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
void	tiny_stack(t_node **lista, t_node **listb, t_data *data)
{
	if (data->size == 2)
		sort_2(*lista);
	else if (data->size == 3)
		sort_3(*lista);
	else if (data->size == 4)
		sort_4(lista, listb);
	else if (data->size == 5)
		sort_5(lista, listb);
}

void	big_stack(t_node **lista, t_node **listb, t_data *data)
{
	t_node	*start;
	
	start = *lista;
	data->j = 0;
	data->k = 0;
	data->max_relative_value = data->size - 1;
	data->max_bit_value = max_bit(data->max_relative_value);
	while (data->j < data->max_bit_value)
	{
		while (data->k < data->max_relative_value && start)
		{
			if ((((*lista)->content >> data->j) & 1) == 1)
			{
				start = start->next;
				rotate(lista, 1);
			}
			else
				push(listb, lista, 2);
			data->k++;
			start = start->next;
		}
		while ((*listb))
		{
			push(lista, listb, 1);
			//*listb = (*listb)->next;
		}
		*listb = NULL;
		data->j++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_node	*lista;
	t_node	*listb;
	
	/* if(argc && argv)
	{
		
	} */
	lista = NULL;
	listb = NULL;
	// t_node first;
	// t_node second;
	// t_node third;

	// first.content = 2;
	// first.next = &second;
	// second.content = 1;
	// second.next = &third;
	// third.content = 0;
	// third.next = NULL;
	// lista = &first;

	// push(&listb, &lista, 2);
	// push(&listb, &lista, 2);
	// push(&lista, &listb, 1);
	// ft_printf("list a is : \n");
	// while(lista != NULL)
	// {
	// 	ft_printf("Node contnt is %d\n", lista->content);
	// 	lista = lista->next;
	// }
	// ft_printf("list b is : \n");
	// while(listb != NULL)
	// {
	// 	ft_printf("node contetn in B is %d\n", listb->content);
	// 	listb = listb->next;
		
	//}
	if (argc > 1)
	{
		data.input = make_it_digestible(argc, argv, &data);
		vibe_check(data.input[0], &data);
		lista = ft_lstnew_pushswap(data.stack_element);
		if (!lista)
			return (0);
		digestive_process(data.input, &data, &lista);
		data.size = ft_lstsize_pushswap(lista);
		if (data.size <= 5)
			tiny_stack(&lista, &listb, &data);
		else if (data.size > 5)
			big_stack(&lista, &listb, &data);
	}
	return (0);
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