/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:44:26 by jalvarad          #+#    #+#             */
/*   Updated: 2021/08/17 16:17:15 by jalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void		swap_rule(t_list **stack, int i);
void		ss_rule(t_list **stack_a, t_list **stack_b);
void		push_rule(t_list **stack_c, t_list **stack_d, int i);
void		rotate_rule(t_list **stack, int i);
void		rr_rule(t_list **stack_a, t_list **stack_b);
void		rev_rotate_rule(t_list **stack, int i);
void		rrr_rule(t_list **stack_a, t_list **stack_b);
int			check_is_sort(t_list *stack);
long int	**array_chunks(long int *sort, int size, t_list **lst);
int			intp_len(long int *array);
int			not_in_stack(t_list **lst, long int *array);
int			last_val(t_list *stack);
int			rev_in_array(int stack_val, long int *array);
void		quit(void);
void		print_lst_chunk(t_list *lst);
void		print_lst(t_list *lst);
int			is_near(t_list *st_a, long int *array_i, long int *array_a);
void		sort_in_b(t_list **st_a, t_list **st_b, long int *array);
void		go_to_sort(t_list **a, t_list **b, long int **array, int array_s);
void		how_sort(t_list **stack_a, t_list **stack_b);
void		push_to_lst2(char **argv, int i, int *j, t_list **stack_a);
int			str_is_nbr(char *str);
long int	*ft_sort_int_tab(long int *tab, int size);
#endif