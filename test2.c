/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:19:59 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/02 15:38:34 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, const char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	char	**tab;

	i = 0;
	printf(">>%d\n", argc);
	if (argc == 1)
		return (0);
	if (argc > 2)
	{
		tab = malloc(sizeof(char) * (argc - 1));
		if (!tab)
			return (1);
		while (i < argc - 1)
		{
			tab[i] = (char*)argv[i + 1];
			printf(" a [%s]\n", tab[i]);
			i++;
		}
	}
	i = 0;
	if (check_args(tab, 0) == 1)
	{
		// ft_push_swap(tab, 0);
		write(1, "yay\n", 4);
	}
	return (1);
}