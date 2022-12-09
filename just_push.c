/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:40:49 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/09 12:07:55 by apirovan         ###   ########.fr       */
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
	tab = malloc(sizeof(int) * new_len);
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
	free(a->stack);
	return (tab);
}

void	ft_push(t_stack *a, t_stack *b)
{
	int	*tab;
	int	i;

	i = 1;
	b->first = a->first;
	a->first = a->stack[1];
	b->stack = new_tab(b, a->stack[0], b->len + 1);
	b->len++;
	a->stack = new_tab(a, 0, a->len - 1);
	a->len--;
	if (a->first == a->max)
		a->max = ft_max(a->stack);
	if (a->first == a->min)
		a->min = ft_min(a->stack);
	if (b->first >= b->max)
		b->max = b->first;
	if (b->first <= b->min)
		b->min = b->first;
}

// void display(int *tab, int len)
// {
//    int i = -1;
//    while (++i < len)
//       printf("[%d] ", tab[i]);
//    printf("\n");
// }
// int main(void)
// {
//    t_stack a;
//    t_stack b;

//    a.stack = malloc(sizeof(int) * 3);
//    a.stack[0] = 1;
//    a.stack[1] = 3;
//    a.stack[2] = 2;
//    a.len = 3;
//    b.stack = malloc(sizeof(int) * 3);
//    b.len = 0;
// //    b.stack[0] = 13;
// //    b.stack[1] = 51;
// //    b.stack[2] = 7;
//    display(a.stack, a.len);
//    display(b.stack, b.len);
//    ft_push(&a, &b);
//    display(a.stack, a.len);
//    display(b.stack, b.len);
// }