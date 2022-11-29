/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:07:00 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/29 15:56:47 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algo()
{

}

int	main(int argc, const char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	char	**tab;

	i = -1;
	tab = malloc(sizeof(char) * (argc - 1));
	if (!tab)
		return (0);
	if (argc >= 2)
	{
		while (argv[++i])
			tab[i] = ft_split(argv[1]);
// FAUT ABSOLUMENT RETEST CA ET VOIR SI CA MARCHE
// !!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!
	}
	else
		return (0);
	i = 0;
	while (tab[i])
	{
		if (ft_check_args(tab[i]) == 1)
		i++;
	}
	ft_push_swap(tab, 0);
	return (1);
}

int	ft_push_swap(char **a, int i)
{
	int		*tab;
	t_stack	*stack1;

	while (a[i])
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		exit(EXIT_FAILURE);
	i = 0;
	while (a[i])
		tab[i] = ft_atoi(a[i]);
	if (ft_check_dbl(tab, i) != 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack1 = ft_tab_to_stack(tab, i);
	ft_algo(stack1, 0);
}
// Lorsque tu reçois tes arguments
// " 1 2 3 54 5" -> Split
// 4 5 2 1 3 5 -> ac - 1
// ARG=""; ./push_swap $ARG -> Split " \n"

// Si no Dup, no non-numeric, no > max int && < Min int -> pushswap
// Sinon, free tab, return, EXIT(1)