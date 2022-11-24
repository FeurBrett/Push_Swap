/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:25:10 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/23 15:25:55 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack;
	int	len;
	int	first;
	int	last;
	int	max;
	int	min;
}	t_stack;

int		ft_isminus(int a);
int		check_args(char **tab, int i);
int		ft_check_error(char	*a);
int		ft_isdigit(int a);
int		ft_check_dbl(int *a, int b);
void	ft_push(t_stack *a, t_stack *b);

#endif