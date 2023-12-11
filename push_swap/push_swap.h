/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:22:20 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/11 19:39:39 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				content;
}	t_node;

typedef struct s_data
{
	int		overflow;
	int		i;
	int		stack_element;
	char	**s_array;
	char	**input;
}	t_data;

#endif