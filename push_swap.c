/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:44:42 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/17 15:59:15 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_to_lst(char **argv)
{
	t_list	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	while (argv[i])
	{
		j = 0;
		push_to_lst2(argv, i, &j, &stack_a);
		i++;
	}
	return (stack_a);
}

void	check_nbrs2(t_list *lst)
{
	int	c;

	c = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		if (c == lst->content)
			quit();
	}
}

void	check_nbrs(t_list *lst)
{
	while (lst->next)
	{
		check_nbrs2(lst);
		lst = lst->next;
	}
}

void	rev_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (str_is_nbr(argv[i]) == 0)
				quit();
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	rev_args(argc, argv);
	if (argc == 1)
		exit(-1);
	stack_a = push_to_lst(argv);
	if (!stack_a)
		quit ();
	check_nbrs(stack_a);
	if (check_is_sort(stack_a))
	{
		ft_lstclear(&stack_a);
		exit (0);
	}
	how_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
