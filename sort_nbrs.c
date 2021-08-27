/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:43:26 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/17 16:20:29 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	*bubble(t_list *s)
{
	t_list		*aux;
	long int	*array;
	int			i;

	aux = s;
	i = 0;
	array = malloc(sizeof(long int) * (ft_lstsize(s) + 1));
	if (!array)
		exit(0);
	while (aux)
	{
		array[i++] = aux->content;
		aux = aux->next;
	}
	array[i] = 2147483648;
	return (ft_sort_int_tab(array, i));
}

static void	sort_high(t_list **s_a, t_list **s_b, int nbr_chunks)
{
	long int	**chunks;
	int			a;
	long int	*array;

	a = 0;
	array = bubble(*s_a);
	chunks = array_chunks(array, nbr_chunks, s_a);
	go_to_sort(s_a, s_b, chunks, nbr_chunks);
	sort_in_b(s_a, s_b, array);
	while (a < nbr_chunks)
	{
		free(chunks[a]);
		a++;
	}
	free (chunks);
	free(array);
}

static void	sort_three_nbrs(t_list **s)
{
	if ((*s)->content > (*s)->next->content && \
		(*s)->content > (*s)->next->next->content)
		rotate_rule(s, 0);
	if ((((*s)->content > (*s)->next->content && \
		(*s)->content < (*s)->next->next->content) || \
		((*s)->content > (*s)->next->content && \
		(*s)->content > (*s)->next->next->content) || \
		((*s)->content < (*s)->next->content && \
		(*s)->content < (*s)->next->next->content)) && \
		!check_is_sort(*s))
		swap_rule(s, 0);
	if ((*s)->content < (*s)->next->content && \
		(*s)->next->content > (*s)->next->next->content)
		rev_rotate_rule(s, 0);
	if ((*s)->content > (*s)->next->content && \
		(*s)->next->content < (*s)->next->next->content)
		rotate_rule(s, 0);
}

void	sort_five(t_list **a, t_list **b)
{
	long int		*array;
	int				i;

	array = bubble(*a);
	i = 0;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content == array[i])
		{
			push_rule(b, a, 1);
			i++;
		}
		else
			rotate_rule(a, 0);
	}
	sort_three_nbrs(a);
	while (ft_lstsize(*b))
		push_rule(a, b, 0);
	free(array);
}

void	how_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 1)
		return ;
	if (ft_lstsize(*stack_a) == 2 && \
		(*stack_a)->content > (*stack_a)->next->content)
		swap_rule(stack_a, 0);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three_nbrs(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 20)
		sort_high(stack_a, stack_b, 2);
	else if (ft_lstsize(*stack_a) <= 250)
		sort_high(stack_a, stack_b, 11);
	else if (ft_lstsize(*stack_a) > 250)
		sort_high(stack_a, stack_b, 26);
}
