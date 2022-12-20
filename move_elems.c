/* ************************************************************************** */
/*          3                                                                  */
/*                                                        :::      ::::::::   */
/*   move_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:02:24 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/13 18:28:50 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_stack *a, t_stack *b, t_var *d)
{
	printf ("ft_move launched\n");
	if (d->rra == d->rrb && d->rra == 0)
	{
		ft_move_rr(a, b, d);
		write (1, "rr\n", 3);
	}
	else if (d->rra == d->rrb && d->rra == 1)
		ft_move_rra(a, b, d);
	else
		ft_global_move(a, b, d);
}

void	ft_move_rr(t_stack *a, t_stack *b, t_var *d)
{
	while (d->nb_ri >= 0 && d->nb_rj >= 0)
	{
		ft_rr(a, b);
		d->nb_ri--;
		d->nb_rj--;
	}
	while (d->nb_ri-- >= 0)
	{
		ft_rotate(a);
		write (1, "ra\n", 3);
	}
	while (d->nb_rj-- >= 0)
	{
		ft_rotate(b);
		write (1, "rb\n", 3);
	}
	ft_push (a, b, 'b');
}

void	ft_move_rra(t_stack *a, t_stack *b, t_var *d)
{
	while (d->nb_ri >= 0 && d->nb_rj >= 0)
	{
		ft_rra(a, b);
		d->nb_ri--;
		d->nb_rj--;
	}
	while (d->nb_ri-- >= 0)
	{
		ft_rev_rotate(a);
		write (1, "rra\n", 4);
	}
	while (d->nb_rj-- >= 0)
	{
		ft_rev_rotate(b);
		write (1, "rrb\n", 4);
	}
	ft_push (a, b, 'b');
}

void	ft_global_move(t_stack *a, t_stack *b, t_var *d)
{
	if (d->rra == 1 && d->rrb == 0)
	{
		while (d->nb_ri-- >= 0)
		{
			ft_rev_rotate(a);
			write (1, "rra\n", 4);
		}
		while (d->nb_rj-- >= 0)
		{
			ft_rotate(b);
			write (1, "rb\n", 3);
		}
	}
	else
	{
		while (d->nb_ri-- >= 0)
		{
			ft_rotate(a);
			write (1, "ra\n", 3);
		}
		while (d->nb_rj-- >= 0)
		{
			ft_rev_rotate(b);
			write (1, "rrb\n", 4);
		}
	}
	ft_push (a, b, 'b');
}
