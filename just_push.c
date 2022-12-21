/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:40:49 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/21 12:20:49 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int *a)
{
	int	max;
	int	i;

	i = 0;
	max = -2147483648;
	while (a[i])
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	ft_min(int *a)
{
	int	min;
	int	i;

	i = 0;
	min = 2147483647;
	while (a[i])
	{
		if (a[i] < min)
			min = a[i];
		i++;
	}
	return (min);
}

int	*new_tab(t_stack *a, int b, int new_len)
{
	int	*tab;
	int	i;
	int	j;

	i = -1;
	j = 0;
	tab = malloc(sizeof(int) * a->len);
	if (!a)
		exit(EXIT_FAILURE);
	if (a->len < new_len)
		tab[j++] = b;
	else
		(void)b;
	while (++i < a->len)
	{
		if (a->len > new_len)
			tab[j++] = a->stack[i + 1];
		else
			tab[j++] = a->stack[i];
	}
	a->len = new_len;
//	free(a->stack);
	return (tab);
}

void	ft_push(t_stack *a, t_stack *b, char x)
{
	int	*tab;
	int	i;

	i = 1;
	b->first = a->first;
	a->first = a->stack[1];
	b->stack = new_tab(b, a->stack[0], b->len + 1);
	// free (tab);
	// b->len++;
	a->stack = new_tab(a, 0, a->len - 1);
	// free (tab);
	// a->len--;
	a->min = ft_min(a->stack);
	b->min = ft_min(b->stack);
	a->max = ft_max(a->stack);
	b->max = ft_max(b->stack);
	// if (a->first == a->max)
	// 	a->max = ft_max(a->stack);
	// if (a->first == a->min)
	// 	a->min = ft_min(a->stack);
	// if (b->first >= b->max)
	// 	b->max = b->first;
	// if (b->first <= b->min)
	// 	b->min = b->first;
	write (1, "p", 1);
	write (1, &x, 1);
	write (1, "\n", 1);
}

void	ft_push_back(t_stack *a, t_stack *b)
{
	printf ("push back \n");
	int	i;

	i = b->len;
	printf ("len = [%d]\n", b->len);
	while (i > 0)
	{
		if (b->stack[0] < a->stack[0] && a->stack[0] == a->min)
		{
			while (b->len >= 1)
				ft_push(b, a, 'a');
			i--;
		}
		else if ()
			ft_rotate(a);
		i--;
	}
}

// avant de push back faut voir les placements de b->stack par rapport a a->stack
// si tous les elems de a sont tries et plus grands que b->max, push back
// sinon, si b->stack[0] est plus petit que a->min et a->[0] est a->min, push
// sinon si a->[0] est plus petit que b->[0] mais b->[0] est plus petit que a->max, rotate jusqu'a ce que b->0 soit entre a->first et a->last ?
// si b-[0] est plus grand que a->max push(a) && rotate
// si y a un a->0 est entre 2 elems de b, rotate jusqu'a ce que le plus petit soit b->last
