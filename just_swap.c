/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:08:24 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/29 11:56:30 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *a)
{
	a->stack[0] = a->stack[1];
	a->stack[1] = a->first;
	a->first = a->stack[0];

}

// #include <stdio.h>

// void	display(int *tab, int len)
// {
//    int i = -1;
//    while (++i < len)
//       printf("[%d] ", tab[i]);
//    printf("\n");
// }

// int	main(void)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = malloc(sizeof(t_stack));
// 	a->stack = malloc(sizeof(int) * 3);
// 	a->stack[0] = 2;
// 	a->stack[1] = 5;
// 	a->stack[2] = 67;
// 	a->stack[3] = 87;
// 	b = malloc(sizeof(t_stack));
// 	b->stack = malloc(sizeof(int) * 3);
// 	b->stack[0] = 13;
// 	b->stack[1] = 51;
// 	b->stack[2] = 7;
// 	a->len = 3;
// 	b->len = 3;
// 	a->first = 2;
// 	b->first = 13;
// 	a->last = 67;
// 	b->last = 7;
// 	a->min = 2;
// 	a->max = 67;
// 	b->min = 7;
// 	b->max = 51;
// 	printf("stack avant \n");
// 	printf("first = %d \n", a->first);
// 	display(a->stack, a->len);
// 	ft_swap(a);
// 	printf("stack apres \n");
// 	printf("first = %d \n", a->first);
// 	display(a->stack, a->len);
// 	return (0);
// }