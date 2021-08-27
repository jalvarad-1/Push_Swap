/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:45:17 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/15 15:52:43 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rule(t_list **stack, int i)
{
	t_list	*aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	aux = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next->next = aux;
	if (i == 0)
		write (1, "sa\n", 3);
	if (i == 1)
		write (1, "sb\n", 3);
}

void	ss_rule(t_list **stack_a, t_list **stack_b)
{
	swap_rule(stack_a, 2);
	swap_rule(stack_b, 2);
	write (1, "ss\n", 3);
}

void	push_rule(t_list **stack_c, t_list **stack_d, int i)
{
	t_list	*aux;

	if ((*stack_d) == NULL)
		return ;
	aux = (*stack_d)->next;
	(*stack_d)->next = *stack_c;
	(*stack_c) = *stack_d;
	(*stack_d) = aux;
	if (i == 0)
		write (1, "pa\n", 3);
	if (i == 1)
		write (1, "pb\n", 3);
}

void	rotate_rule(t_list **stack, int i)
{
	t_list	*start;
	t_list	*last;

	start = (*stack);
	(*stack) = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = start;
	start->next = NULL;
	if (i == 0)
		write (1, "ra\n", 3);
	if (i == 1)
		write (1, "rb\n", 3);
}

void	rr_rule(t_list **stack_a, t_list **stack_b)
{
	rotate_rule(stack_a, 2);
	rotate_rule(stack_b, 2);
	write (1, "rr\n", 3);
}
