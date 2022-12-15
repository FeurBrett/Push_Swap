/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_calculs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:57:33 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/15 13:40:04 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nb_move(t_stack *a, t_stack *b, t_var *d, int i)
{
	while (a->stack[i] && b->stack[d->j])
	{
		ft_explore_b(a, b, d, i);
		i++;
	}
	if (d->index < a->len / 2)
	{
		d->rra = 0;
		d->nb_ri = d->index;
	}
	else
		d->nb_ri = a->len - d->index;
	d->nb_r = d->nb_ri + d->nb_rj;
	if (d->nb_r < d->min_nb_r)
	{
		d->min_nb_r = d->nb_r;
		d->index = i;
	}
	printf("nb de moves: [%d]\nindex :[%d]\n", d->min_nb_r, d->index);
}

void	find_max(t_stack *b, t_var *d)
{
	int	i;

	i = 0;
	while (b->stack[i] != b->max)
		i++;
	if (i > b->len / 2)
	{
		d->nb_rj = b->len - i;
		d->rrb = 1;
	}
	else
	{
		d->nb_rj = i;
		d->rrb = 0;
	}
}

void	find_min(t_stack *a, t_stack *b, t_var *d)
{
	int	i;

	i = 0;
	while (b->stack[i] != b->min)
		i++;
	if (i == b->len - 1)
		d->nb_rj = 0;
	else if (i + 1 > b->len / 2)
	{
		d->nb_rj = b->len - i;
		d->rrb = 1;
	}
	else
	{
		d->nb_rj = i + 1;
		d->rrb = 0;
	}
}

void	ft_explore_b(t_stack *a, t_stack *b, t_var *d, int i)
{
	while (d->j < b->len)
	{
		if (a->stack[i] < b->stack[d->j]
			&& a->stack[i] > b->stack[d->j + 1])
		{
			if (d->j > b->len / 2)
				d->nb_rj = b->len - d->j;
			else
			{
				d->nb_rj = d->j;
				d->rrb = 0;
			}
		}
		d->j++;
	}
	if (a->stack[i] >= b->max)
		find_max(b, d);
	if (a->stack[i] <= b->min)
		find_min(a, b, d);
}

// en gros faut utiliser min_nb_r qq part sinon la il a jamais aucune valeur
// ptet faire via un tab dans t_var qui stocke le nb_r pour chaque elem de a0
// faudra donc maloc size int * a->len ofc, faudra faire de ft comme dans move elem
// avec les rra et rrb pour savoir cb de rr ou rrr faut faire aussi, comme ca on
// a le bon nombre. Y a deja un debut dans ft_nb_move mais bon...