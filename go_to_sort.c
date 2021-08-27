/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:22:00 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/17 16:18:22 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	light_sort_b(t_list **a, t_list **b, long int *ar, long int *ar_s)
{
	if ((*a) && !(rev_in_array((*a)->content, ar_s)) && \
		!(rev_in_array((*a)->content, ar)) && \
		rev_in_array((*b)->content, ar))
		rr_rule(a, b);
	else if (rev_in_array((*b)->content, ar))
		rotate_rule(b, 1);
}

static int	what_rule(t_list *stack, long int *array, long int *a_array)
{
	int	i;

	i = last_val(stack);
	if (rev_in_array(stack->content, array) || \
		rev_in_array(stack->content, a_array))
		return (1);
	if (rev_in_array(i, array) || rev_in_array(i, a_array))
		return (2);
	return (0);
}

static void	go_to_sort2(t_list **a, t_list **b, long int *ar_i, long int *ar_a)
{
	while ((*a) && !(rev_in_array((*a)->content, ar_i)) && \
			!(rev_in_array((*a)->content, ar_a)))
	{
		if (what_rule(*a, ar_i, ar_a) == 2 )
			rev_rotate_rule(a, 0);
		else
			rotate_rule(a, 0);
	}
	while ((*a) && (rev_in_array((*a)->content, ar_i) || \
		rev_in_array((*a)->content, ar_a)))
	{
		push_rule(b, a, 1);
		if (ft_lstsize(*b) > 1)
			light_sort_b(a, b, ar_i, ar_a);
	}
}

void	go_to_sort(t_list **a, t_list **b, long int **array, int array_s)
{
	int	i;
	int	j;

	i = (array_s / 2) - 1;
	j = i + 1;
	while ((*a) && j < array_s)
	{
		go_to_sort2(a, b, array[i], array[j]);
		if ((*a) && !not_in_stack(a, array[i]) && i > 0)
			i--;
		if ((*a) && !not_in_stack(a, array[j]) && j < array_s - 1)
			j++;
	}
}

long int	*ft_sort_int_tab(long int *tab, int size)
{
	int			x;
	int			y;
	long int	aux;

	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (tab[y] > tab[x])
			{
				aux = tab[x];
				tab[x] = tab[y];
				tab[y] = aux;
			}
			y++;
		}
		x++;
	}
	return (tab);
}
