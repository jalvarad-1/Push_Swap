/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils_fts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:45:44 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/17 16:12:37 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sort(t_list *stack)
{
	int	i;

	i = stack->content;
	while (stack->next)
	{
		if (i > stack->next->content)
			return (0);
		stack = stack->next;
		if (stack)
			i = stack->content;
	}
	return (1);
}

int	str_is_nbr(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] != ' ' && str[a] != '\t' && \
			(str[a] < '0' || str[a] > '9') && \
			str[a] != '-' && str[a] != '+')
			return (0);
		a++;
	}
	a = 0;
	while (str[a] != '\0')
	{
		if (a == 0 && (str[a] == '-' || str[a] == '+') && \
			(str[a + 1] < '0' || str[a + 1] > '9'))
			return (0);
		else if ((str[a] == '-' || str[a] == '+') && \
			(str[a + 1] < '0' || str[a + 1] > '9') && \
			(str[a + 1] >= '0' || str[a + 1] <= '9'))
			return (0);
		a++;
	}
	return (1);
}

static void	save_nbr(t_list **stack, int num)
{
	t_list	*tmp;

	if (*stack == NULL)
		*stack = ft_lstnew(num);
	else
	{
		tmp = ft_lstnew(num);
		ft_lstadd_back(stack, tmp);
	}
}

void	push_to_lst2(char **argv, int i, int *j, t_list **stack_a)
{
	long int	nbr;

	nbr = 0;
	while (argv[i][(*j)])
	{
		nbr = ft_atoi((argv[i] + (*j)));
		if (nbr > INT_MAX || nbr < INT_MIN)
			quit();
		save_nbr(stack_a, nbr);
		while (argv[i][(*j)] == '-' || argv[i][(*j)] == '+')
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
		while (ft_isdigit(argv[i][(*j)]))
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
	}
}
