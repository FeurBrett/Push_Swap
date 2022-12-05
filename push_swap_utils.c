/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:15:37 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/05 14:18:16 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **tab, int i)
{
	int	j;
	int	k;

	while (tab[i])
	{
		ft_check_error(tab[i]);
		j = 0;
		k = 0;
		while (tab[i][j])
		{
			if (ft_isminus(tab[i][0]) == 1 && k == 0 && tab[i][0])
			{
				j++;
				k = 1;
			}
			if (ft_isdigit(tab[i][j]) == 1)
				j++;
			else
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	return (1);
}

int	ft_check_error(char	*a)
{
	if (a[0] == '\0')
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	ft_check_dbl(int *a, int b)
{
	int	i;
	int	j;

	i = 0;
	while (i < b)
	{
		j = 0;
//		write(1, "boucle1\n", 8);
		while (j != i)
		{
//			write(1, "boucle2\n", 8);
			if (a[i] == a[j])
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long	nb;
	int		minus;

	minus = 1;
	nb = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + *str - 48;
		if (nb * minus > 2147483647)
			return (-1);
		if (nb * minus < -2147483648)
			return (0);
		str++;
	}
	return (nb * minus);
}

t_stack	*ft_tab_to_stack(int *a, int i)
{
	t_stack	*stack1;

	stack1 = malloc(sizeof(t_stack));
	stack1->len = i;
	stack1->stack = malloc(sizeof(int) * i);
	stack1->stack = a;
	stack1->first = stack1->stack[0];
	stack1->last = stack1->stack[i - 1];
	i = 0;
	stack1->max = -2147483648;
	stack1->min = 2147483647;
	while (i < stack1->len)
	{
		if (stack1->stack[i] < stack1->min)
			stack1->min = stack1->stack[i];
		if (stack1->stack[i] > stack1->max)
			stack1->max = stack1->stack[i];
		i++;
	}
	return (stack1);
}
