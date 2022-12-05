/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nico.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:58:19 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/29 13:58:21 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int *new_tab(t_stack *a, int b, int new_len)
{
   int *tab;
   int i,j;

   i = -1;
   j = 0;
   tab = malloc(sizeof(int) * new_len);
   if (a->len < new_len)
      tab[j++] = b;
   else
      (void)b;
   while (++i < a->len)
   {
      if (a->len > new_len)
         tab[j++] = a->stack[i + 1];
      else
         tab[j++] = a->stack[i];
   }
   free(a->stack);
   return (tab);
}
void   push(t_stack *a, t_stack *b)
{
   a->stack = new_tab(a, b->stack[0], a->len + 1);
   a->len++;
   b->stack = new_tab(b, 0, b->len - 1);
   b->len--;
}

void display(int *tab, int len)
{
   int i = -1;
   while (++i < len)
      printf("[%d] ", tab[i]);
   printf("\n");
}
int main(void)
{
   t_stack a;
   t_stack b;

   a.stack = malloc(sizeof(int) * 4);
   a.stack[0] = 2;
   a.stack[1] = 5;
   a.stack[2] = 67;
   a.stack[3] = 1;
   a.len = 4;
   b.stack = malloc(sizeof(int) * 3);
   b.len = 3;
   b.stack[0] = 13;
   b.stack[1] = 51;
   b.stack[2] = 7;
   display(a.stack, a.len);
   display(b.stack, b.len);
   push(&a, &b);
   display(a.stack, a.len);
   display(b.stack, b.len);
}