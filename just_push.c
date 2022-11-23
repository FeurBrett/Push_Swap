/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:40:49 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/23 15:28:33 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *a, t_stack *b)
{
	int	*tab;
	int	i;

	i = 1;
	b->first = a->first;
	a->len = a->len - 1;
	b->len = b->len + 1;
	tab = ft_stack_to_tab(b, tab, "+");
	b->stack = ft_malloc_stack(b, tab, 0);
	tab = ft_stack_to_tab(a, tab, "0");
	a->stack = ft_malloc_stack(b, tab, 1);
	if (a->first == a->max)
		a->max = ft_max(a->stack);
	if (a->first == a->min)
		a->min = ft_min(a->stack);
	if (b->first >= b->max)
		b->max = b->first;
	if (b->first <= b->min)
		b->min = b->first;
}

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

int	*ft_stack_to_tab(t_stack *a, int	*tab, char sign)
{
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * a->len);
	if (!tab)
	{
		write(1, "Error", 6);
		exit(EXIT_FAILURE);
	}
	if (sign == "+")
		tab[0] = a->first;
	while (i <= a->len)
	{
		tab[i] = a->stack[i - 1];
		i++;
	}
	free(a->stack);
	return (tab);
}

int	*ft_malloc_stack(t_stack *b, int *tab, int i)
{
	int	j;

	j = 0;
	b->stack = malloc(sizeof(int) * b->len);
	if (!b->stack)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (i != 0)
		b->stack[0] = b->first;
	while (tab[j])
	{
		b->stack[i] = tab[j];
		i++;
		j++;
	}
	free(tab);
	return (b->stack);
}
