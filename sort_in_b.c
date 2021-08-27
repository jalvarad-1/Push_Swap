/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:12:34 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/15 15:59:41 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b3( t_list **st_b, long int *array, int *j, int i)
{
	while ((*st_b) && (*j) > 0)
	{
		rev_rotate_rule(st_b, 1);
		(*j)--;
		if (array[i] == (*st_b)->content)
			break ;
	}
}

static void	sort_in_b2(t_list **st_a, t_list **st_b, long int *array, int *i)
{
	while ((*st_b) && array[(*i)] != 2147483648 && \
		array[(*i)] == (*st_b)->content)
	{
		push_rule(st_a, st_b, 0);
		(*i)--;
	}
}

void	sort_in_b(t_list **st_a, t_list **st_b, long int *array)
{
	int	i;
	int	j;

	i = intp_len(array) - 1;
	j = 0;
	while ((*st_b) && array[i] != 2147483648)
	{
		while (array[i] != 2147483648 && array[i] != (*st_b)->content)
		{
			if ((*st_b)->next && array[i] == (*st_b)->next->content)
				swap_rule(st_b, 1);
			else
			{
				rotate_rule(st_b, 1);
				j++;
			}
		}
		sort_in_b2(st_a, st_b, array, &i);
		sort_in_b3(st_b, array, &j, i);
	}
}
