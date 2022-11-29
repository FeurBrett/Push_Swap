/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:09:07 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/29 12:49:28 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *a)
{
	int	i;

	i = 0;
	a->last = a->first;
	while (i < a->len - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = a->first;
	a->first = a->stack[0];
}

void	ft_rev_rotate(t_stack *a)
{
	int	j;

	j = a->len - 1;
	a->first = a->last;
	a->last = a->stack[a->len - 1];
	while (j > 0)
	{
		a->stack[j] = a->stack[j - 1];
		j--;
	}
	a->stack[0] = a->first;
	a->last = a->stack[a->len - 1];
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}

// #include <stdio.h>

// void	display(int *tab, int len)
// {
//    int i = -1;
//    while (++i < len)
//       printf("[%d] \n", tab[i]);
//    printf("\n");
// }

// int	main(void)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = malloc(sizeof(t_stack));
// 	a->stack = malloc(sizeof(int) * 5);
// 	a->stack[0] = 2;
// 	a->stack[1] = 5;
// 	a->stack[2] = 67;
// 	a->stack[3] = 87;
// 	a->stack[4] = 8;
// 	b = malloc(sizeof(t_stack));
// 	b->stack = malloc(sizeof(int) * 3);
// 	b->stack[0] = 13;
// 	b->stack[1] = 51;
// 	b->stack[2] = 7;
// 	a->len = 5;
// 	b->len = 3;
// 	a->first = 2;
// 	b->first = 13;
// 	a->last = 8;
// 	b->last = 7;
// 	a->min = 2;
// 	a->max = 67;
// 	b->min = 7;
// 	b->max = 51;
// 	printf("stack avant \n");
// 	printf("first = %d \n", b->first);
// 	display(b->stack, b->len);
// 	printf("last = %d \n", b->last);
// 	ft_rr(a, b);
// 	printf("stack apres \n");
// 	printf("first = %d \n", b->first);
// 	printf("last = %d \n", b->last);
// 	display(b->stack, b->len);
// 	return (0);
// }