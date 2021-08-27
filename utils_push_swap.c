/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:30:50 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/17 16:10:57 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_val(t_list *stack)
{
	int	last;

	while (stack->next)
		stack = stack->next;
	last = stack->content;
	return (last);
}

int	rev_in_array(int stack_val, long int *array)
{
	int	i;
	int	j;

	i = intp_len(array);
	j = 0;
	while (j < i)
	{
		if (stack_val == array[j])
			return (1);
		j++;
	}
	return (0);
}

int	not_in_stack(t_list **lst, long int *array)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = *lst;
	while (*lst)
	{
		i = 0;
		while (i < intp_len(array))
		{	
			if ((*lst)->content == array[i])
			{
				(*lst) = aux;
				return (1);
			}
			i++;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = aux;
	return (0);
}

int	intp_len(long int *array)
{
	int	i;

	i = 0;
	while (array[i] != 2147483648)
		i++;
	return (i);
}

void	quit(void)
{
	write(1, "Error\n", 6);
	exit(-1);
}
