/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:07:00 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/05 15:24:06 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_algo(t_stack *a, int i)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (a->len == 3)
		if_three(a, b);
}

int	main(int argc, const char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	char	**tab;

	i = 0;
	if (argc == 1)
		return (0);
	else if (argc > 2)
	{
		tab = (char **)malloc(sizeof(char *) * argc);
		if (!tab)
			return (1);
		while (i < argc - 1)
		{
			tab[i] = ft_strdup(argv[i + 1]);
			i++;
		}
	}
	else
		tab = ft_split(argv[1], ' ');
	if (check_args(tab, 0) == 1)
		ft_push_swap(tab, 0);
	return (1);
}

int	ft_push_swap(char **a, int i)
{
	int		*tab;
	t_stack	*stack1;

	while (i < ft_len_array(a))
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < ft_len_array(a))
	{
		printf ("iterations : [%d]\n", i);
		printf ("a[i] = %s\n", a[i]);
		tab[i] = ft_atoi(a[i]);
		printf ("atoi : [%d]\n", tab[i]);
		i++;
	}
	free(a);
	write (1, "checking for doubles.\n", 22);
	if (ft_check_dbl(tab, i) != 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	write (1, "check done.\n", 12);
	stack1 = ft_tab_to_stack(tab, i);
	i = 0;
	ft_algo(stack1, 0);
	return (0);
}
// Lorsque tu reçois tes arguments
// " 1 2 3 54 5" -> Split
// 4 5 2 1 3 5 -> ac - 1
// ARG=""; ./push_swap $ARG -> Split " \n"

// Si no Dup, no non-numeric, no > max int && < Min int -> pushswap
// Sinon, free tab, return, EXIT(1)