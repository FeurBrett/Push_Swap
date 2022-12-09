/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:56:20 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/09 12:09:37 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three(t_stack *a, t_stack *b)
{
	if (a->first < a->stack[1] && a->stack[1] < a->last)
		write(1, "ok\n", 3);
	else if (a->first < a->stack[1] && a->stack[1] > a->last)
	{
		ft_three(a, b);
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

void	ft_three(t_stack *a, t_stack *b)
{
	if (a->first < a->last)
	{
		ft_rev_rotate(a);
		ft_swap(a);
	}
	else
		ft_rev_rotate(a);
}

// int	if_five(t_stack *a)
// {

// }

// int	if_more(t_stack *a, t_stack *b)
// {
// 	ft_push(a, b);
// 	ft_push(a, b);
// 	ft_nb_move(a, b);
// }

// void	ft_nb_move(t_stack *a, t_stack *b)
// {
	
// 	if (a->first < b->first)
// 	{
// 		if (b->last == b->max)
// 			ft_push(a, b);
// 	}
	
// }