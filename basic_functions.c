/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:20:27 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/05 14:02:25 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char a)
{
	if (a < '0' || a > '9')
		return (0);
	else
		return (1);
}

int	ft_isminus(char a)
{
	if (a != '-' && a != '+')
		return (0);
	else
		return (1);
}

int ft_len_array(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while ((char *)(tab)[i] != NULL)
		i++;
	return (i);
}