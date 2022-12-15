/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:07:00 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/15 17:31:48 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_algo(t_stack *a, int i)
{
	t_stack	*b;
	t_var	*d;

	b = malloc(sizeof(t_stack));
	d = malloc(sizeof(t_var));
	if (a->len == 2)
	{
		if (a->stack[0] < a->stack[1])
			return (0);
		else
		{
			ft_swap(a);
			a->last = a->stack[1];
		}
	}
	else if (a->len == 3)
		if_three(a);
	else
	{
		int i = -1;
		printf ("stacks before pb pb\na\n");
		while (i++ < a->len - 1)
			printf("[%d]", a->stack[i]);
		i = -1;
		printf("\nb\n");
		while (i++ < b->len - 1)
			printf("[%d]", b->stack[i]);
		ft_push(a, b, 'b');
		ft_push(a, b, 'b');
		i = -1;
		printf ("stacks after pb pb\na\n");
		while (i++ < a->len - 1)
			printf("[%d]", a->stack[i]);
		i = -1;
		printf("\nb\n");
		while (i++ < b->len - 1)
			printf("[%d]", b->stack[i]);
		ft_more(a, b, d);
	}
	return (0);
}

int	main(int argc, const char **argv)
{
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
	if (check_args(tab, 0, 0) == 1)
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
		tab[i] = ft_atoi(a[i]);
		printf ("atoi [%d]: [%d]\n", i + 1, tab[i]);
		i++;
	}
	free(a);
	write (1, "checking for doubles.\n", 22);
	if (ft_check_dbl(tab, i) != 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack1 = ft_tab_to_stack(tab, i);
	i = 0;
	ft_algo(stack1, 0);
	while (i < stack1->len)
	{
		printf("[%d]\n", stack1->stack[i]);
		i++;
	}
	printf ("len : [%d]\nmax : [%d]\nmin : [%d]\nfirst : [%d]\nlast : [%d]\n", stack1->len, stack1->max, stack1->min, stack1->first, stack1->last);
	return (0);
}
// Lorsque tu reçois tes arguments
// " 1 2 3 54 5" -> Split
// 4 5 2 1 3 5 -> ac - 1
// ARG=""; ./push_swap $ARG -> Split " \n"

// Si no Dup, no non-numeric, no > max int && < Min int -> pushswap
// Sinon, free tab, return, EXIT(1)