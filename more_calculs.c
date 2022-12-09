/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_calculs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:57:33 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/09 19:05:38 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_more(t_stack *a, t_stack *b, t_stack	*c, int i)
{
	int	nb_r;
	int	j;
	int	nb_ri;
	int	nb_rj;

	nb_r = 0;
	nb_ri = 0;
	nb_rj = 0;
	j = 0;
	while (ft_check_order(a) != 0)
	{
		while (a->stack[i] && b->stack[j])
		{
			if (a->stack[i] < b->stack[j] && a->stack[i] > b->stack[j + 1])
			{

			}
			if (a->stack[i] >= b->max)
			if (a->stack[i] <= b->max)
		}
	}

}

int	ft_check_order(t_stack	*a)
{
	int	i;

	i = 0;
	while (a->stack[i])
	{
		if (a->stack[i] < a->max && a->stack < a->stack[i + 1])
			i++;
		if (a->stack[i + 1] == a->min && a->stack[i] == a->max)
			i++;
	}
	if (i == a->len)
		return (0);
	else
		return (1);
}