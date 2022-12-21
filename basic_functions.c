/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:20:27 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/21 15:28:30 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int a)
{
	if (a < '0' || a > '9')
		return (0);
	else
		return (1);
}

int	ft_isminus(int a)
{
	if (a != '-' && a != '+')
		return (0);
	else
		return (1);
}

int	ft_len_array(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while ((char *)(tab)[i] != NULL)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}