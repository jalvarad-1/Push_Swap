/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:45:10 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/15 15:53:42 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_rule(t_list **stack, int i)
{
	t_list	*aux;
	t_list	*last;
	int		c;

	c = ft_lstsize(*stack);
	aux = (*stack);
	last = ft_lstlast(*stack);
	last->next = (*stack);
	while (c-- > 2)
	{
		aux = aux->next;
	}
	aux->next = NULL;
	(*stack) = last;
	if (i == 0)
		write (1, "rra\n", 4);
	if (i == 1)
		write (1, "rrb\n", 4);
}

void	rrr_rule(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_rule(stack_a, 2);
	rev_rotate_rule(stack_b, 2);
	write (1, "rrr\n", 4);
}
