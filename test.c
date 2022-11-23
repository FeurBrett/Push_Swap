/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:59:04 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/23 16:49:12 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// int ft_check_dbl(int a[], int len)
// {
//     int    i;
//     int    j;

//     i = 0;
//     while (a[i])
//     {
//         j = i + 1;
//         while (j <= len)
//         {
//             if (a[i] != a[j])
//                 j++;
//             else
//                 return (-1);
//         }
//         i++;
//     }
//     return (0);
// }

// int main (void)
// {
//     int len = 5;
//     int a[len];
//     //int b;
    
//     a[0] = 2;
//     a[1] = 4;
//     a[2] = 3;
//     a[3] = 1;
//     a[4] = 4;
//     printf("%d", ft_check_dbl(a, len));
    
//     return (1);
// }

// int	check_args(char **tab, int i)
// {
// 	int	j;
// 	int	k;

// 	while (tab[i])
// 	{
// 		ft_check_error(tab[i]);
// 		j = 0;
// 		k = 0;
// 		while (tab[i][j])
// 		{
// 			if (ft_isminus(tab[i][0]) == 1 && k == 0 && tab[i][0])
// 			{
// 				j++;
// 				k = 1;
// 			}
// 			if (ft_isdigit(tab[i][j]) == 1)
// 				j++;
// 			else
// 				return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	ft_check_error(char	*a)
// {
// 	if (a[0] == '\0')
// 	{
// 		write(1, "Error\n", 6);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (1);
// }

// int	ft_check_dbl(int *a, int b)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < b)
// 	{
// 		j = 0;
// 		write(1, "boucle1\n", 8);
// 		while (j != i)
// 		{
// 			write(1, "boucle2\n", 8);
// 			if (a[i] == a[j])
// 			{
// 				write(1, "Error, same argument passed twice\n", 34);
// 				exit(EXIT_FAILURE);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int main()
// {
//     int    *tab;
// 	int	i;

// 	tab = malloc(sizeof(char *) * 4);
//     tab[0] = 0;
//     tab[1] = 1;
//     tab[2] = 3;
//     tab[3] = 221;
//     while ( i < 4)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
//     printf("%d", ft_check_dbl(tab, 4));
// }

int	*ft_stack_to_tab(t_stack *a, int	*tab, char sign)
{
	printf("%s", "stacktotab\n");
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * a->len);
	if (!tab)
	{
		write(1, "Error", 6);
		exit(EXIT_FAILURE);
	}
	if (sign == '+')
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
	printf("%s", "mallocstack\n");
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

void	ft_push(t_stack *a, t_stack *b)
{
	int	*tab;
	int	i;

	i = 1;
	b->first = a->first;
	a->len = a->len - 1;
	b->len = b->len + 1;
	tab = ft_stack_to_tab(b, tab, '+');
	b->stack = ft_malloc_stack(b, tab, 0);
	tab = ft_stack_to_tab(a, tab, '0');
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

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	a = malloc(sizeof(t_stack));
	a->stack = malloc(sizeof(int) * 3);
	a->stack[0] = 1;
	a->stack[1] = 5;
	a->stack[2] = 67;
	b = malloc(sizeof(t_stack));
	b->stack = malloc(sizeof(int) * 3);
	b->stack[0] = 13;
	b->stack[1] = 51;
	b->stack[2] = 7;
	a->len = 3;
	b->len = 3;
	a->first = 1;
	b->first = 13;
	a->last = 67;
	b->last = 7;
	a->min = 1;
	a->max = 67;
	b->min = 7;
	b->max = 51;
	ft_push(a,b);
	printf("%d%s%d", a->stack[1], "\n", b->stack[1]);

	return(0);
}
