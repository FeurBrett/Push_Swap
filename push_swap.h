/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:25:10 by apirovan          #+#    #+#             */
/*   Updated: 2022/12/13 18:10:18 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int	*stack;
	int	len;
	int	first;
	int	last;
	int	max;
	int	min;
}	t_stack;

typedef struct s_var
{
	int	nb_r;
	int	j;
	int	nb_ri;
	int	nb_rj;
	int	rrb;
	int	rra;
	int	index;
	int	min_nb_r;
}	t_var;

// basics functions
int		ft_isminus(int a);
int		check_args(char **tab, int i, int j);
int		ft_check_error(char	*a);
int		ft_isdigit(int a);
int		ft_check_dbl(int *a, int b);
char	**ft_split(char const *s, char c);
int		ft_push_swap(char **a, int i);
int		ft_atoi(char *str);
t_stack	*ft_tab_to_stack(int *a, int i);
int		ft_len_array(char **tab);
char	*ft_strdup(const char *src);

// Les mouvements

void	ft_rotate(t_stack *a);
void	ft_rev_rotate(t_stack *a);
void	ft_swap(t_stack *a);
void	ft_push(t_stack *a, t_stack *b, char x);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a, t_stack *b);

// l'algo

void	if_three(t_stack *a);
void	ft_three(t_stack *a);
void	ft_more(t_stack *a, t_stack *b, t_var *d);
void	ft_push_back(t_stack *a, t_stack *b);
int		ft_check_order(t_stack	*a);
void	ft_explore_b(t_stack *a, t_stack *b, t_var *d, int i);
void	ft_nb_move(t_stack *a, t_stack *b, t_var *d, int i);
void	find_max(t_stack *b, t_var *d);
void	find_min(t_stack *a, t_stack *b, t_var *d);
void	ft_move(t_stack *a, t_stack *b, t_var *d);
void	ft_move_rr(t_stack *a, t_stack *b, t_var *d);
void	ft_move_rra(t_stack *a, t_stack *b, t_var *d);
void	ft_global_move(t_stack *a, t_stack *b, t_var *d);

#endif