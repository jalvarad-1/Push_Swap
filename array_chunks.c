/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:45:53 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/15 15:49:57 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putchunksval(long int *a, int c_nbr, t_list **lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = *lst;
	while (*lst)
	{
		i = 0;
		while (a[i] != 2147483648)
		{	
			if ((*lst)->content == a[i])
				(*lst)->chunk = c_nbr;
			i++;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = aux;
}

static long int	*mod_memcpy(long int *src, int size)
{
	int			i;
	long int	*dst;

	dst = malloc(sizeof(long int) * (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 2147483648;
	return (dst);
}

static long int	*other_mod_memcpy(long int *src)
{
	int			size;
	int			i;
	long int	*dst;

	i = 0;
	size = 0;
	while (src[size] != 2147483648)
		size++;
	dst = malloc(sizeof(long int) * (size + 1));
	if (!dst)
		return (NULL);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 2147483648;
	return (dst);
}

void	array_chunks2(long int **aux, long int *sort, int size, t_list **lst)
{
	int	p;
	int	j;
	int	len;
	int	i;

	len = intp_len(sort);
	i = len / size;
	p = 0;
	j = 0;
	while (j < size)
	{	
		if (j == size - 1)
			aux[j] = other_mod_memcpy((sort + p));
		else
			aux[j] = mod_memcpy((sort + p), i);
		putchunksval(aux[j], j, lst);
		p = p + i;
		len = len - i;
		j++;
	}
}

long int	**array_chunks(long int *sort, int size, t_list **lst)
{	
	long int	**aux;

	aux = (long int **)malloc(sizeof(long int *) * size);
	if (!aux)
		exit (0);
	array_chunks2(aux, sort, size, lst);
	return (aux);
}
