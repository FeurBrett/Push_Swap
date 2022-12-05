/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:56:20 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/05 15:46:57 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_three(t_stack *a, t_stack *b)
{
	if (a->first < a->stack[1] && a->stack[1] < a->last)
		return (0);
	else if (a->first < a->stack[1] && a->stack[1] > a->last)
	{
		ft_rotate(a);
		ft_push(a, b);
		ft_rotate(a);
		ft_push(b, a);
	}
	// else if (a->first > a->stack[1] && a->stack[1] < a->last)
	// 	ft_rev_rotate(a);
	else if (a->first > a->stack[1] && a->stack[1] > a->last)
	{
		ft_push(a, b);
		ft_rotate(a);
		ft_push(b, a);
	}
// 	else if (a->first < a->stack[1] && a->stack[1] > a->last)
// 		ft_rev_rotate(a);
// }

int	if_five(t_stack *a)
{

}

int	if_more(t_stack *a)
{
	
}