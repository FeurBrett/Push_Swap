/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:56:20 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/15 15:47:18 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three(t_stack *a)
{
	if (a->first < a->stack[1] && a->stack[1] < a->last)
		write(1, "ok\n", 3);
	else if (a->first < a->stack[1] && a->stack[1] > a->last)
	{
		ft_three(a);
	}
	else if (a->first > a->stack[1] && a->stack[1] < a->last)
	{
		if (a->first > a->last)
			ft_rotate(a);
		else
			ft_swap(a);
	}
	else if (a->first > a->stack[1] && a->stack[1] > a->last)
	{
		ft_swap(a);
		ft_rev_rotate(a);
	}
	else if (a->first < a->last)
		ft_rev_rotate(a);
	else
		ft_rotate(a);
}

void	ft_three(t_stack *a)
{
	if (a->first < a->last)
	{
		ft_rev_rotate(a);
		ft_swap(a);
	}
	else
		ft_rev_rotate(a);
}

// void	if_five(t_stack *a, t_stack *b)
// {
// 	ft_push(a, b);
// 	ft_push(a, b);
// 	ft_three (a);
// 	ft_push_back(a, b);
// }

void	ft_more(t_stack *a, t_stack *b, t_var *d)
{
	// int	index;

	// index = 0;
	d->nb_r = 0;
	d->nb_ri = 0;
	d->nb_rj = 0;
	d->j = 0;
	d->rrb = 1;
	d->rra = 1;
	while (ft_check_order(a) != 1 || a->len > 3)
	{
		ft_nb_move(a, b, d, 0);
		ft_move(a, b, d);
	}
	if (a->len == 3)
		if_three(a);
	int i = 0;
	printf ("b stack before push back\n");
	while (b->stack[i])
	{
		printf("[%d]", b->stack[i]);
		i++;
	}
	ft_push_back(a, b);
	i = 0;
	printf ("b stack after push back\n");
	while (b->stack[i])
	{
		printf("[%d]", b->stack[i]);
		i++;
	}
	printf("\nlen b after pushback [%d]\n", b->len);
}

int	ft_check_order(t_stack	*a)
{
	int	i;

	i = 0;

	while (i < a->len - 1)
	{
		if (a->stack[i] < a->stack[i + 1] && a->stack[i] != a->max)
			i++;
		else if (a->stack[i] == a->max && a->stack[i + 1] == a->min)
			i++;
		else
			return (0);
	}
	return (1);
}
