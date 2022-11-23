/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:20:27 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/22 15:20:41 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ce fichiers contient des fonctions basiques nécessaires à la vérification des
// arguments passés en paramètre au programme push_swap.

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


//int **create_tab_sngl(char a[])
// {

// }

//int	**create_tab_mult()