/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:09:11 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 02:59:33 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The algorithm used is use one "pivot or pvt" as reference for the operations
** The 'check_pivot' in this case is responsible for findinf if the number at
** the top of the stack 'a' is lower or equals the pivot found;
** The pivot in this case will be the higher value of the chunck;
**
** Met its conditions, it will push the top number to the stack 'b',
** basicaly, preparing the chunks of numbers to sort;
**
** Although, if not met, the number will pass through a smart 
** rotation of the stack 'a'
*/
void	first_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		pvt;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i >= ft_abs(len / 4))
	{
		tmp1 = ft_lst_dup(*a);
		pvt = get_pivot(tmp1);
		while (check_pivot((*a), pvt, 1) && (*a))
		{
			if ((*a)->num <= pvt)
			{
				tmp2 = *a;
				pick_case(a, b, PB, v);
				i--;
				free(tmp2);
			}
			else
				normalize_a(a, b, v, pvt);
		}
		free_stk(&tmp1);
	}
}

/*
** When just the higher numbers remains in stack 'a' (still unsorted)
** It will pick top number of stack 'a' and send to stack 'b'
** if it is the lower number, otherwise it will smart rotate the stack;
**
** This operation will continue while the list has numbers;
*/
void	second_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		min;
	t_stk	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = get_min(*a);
		tmp = (*a)->nxt;
		while ((*a)->num != min && tmp && tmp->num == min)
			pick_case(a, b, SA, v);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->num == min)
			{
				tmp = *a;
				pick_case(a, b, PB, v);
				free(tmp);
				len--;
			}
			else
				normalize_a(a, b, v, min);
		}
	}
}

/*
** Thist part is responsible for returning the numbers in the correct
** order.
** The pivot (max) is set to be the higher number in the stack 'b';
**
** First of all, while the pivot and the top of stack 'b' is equals
** it pushes the number to top of stack 'a'. 
** Otherwise, it will smart rotate the stack 'b' until the top number
** is the same as the pivot, when it will be sent to the top of stack
** 'a' as well. After the operation, it will find the maximun number
** again to adapt to the ajusted stack.
**
** In the end, all stack 'b' will be arranged in the stack 'a'.
*/
void	third_sort(t_stk **a, t_stk **b, int max, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = get_max(*b);
			tmp = (*b)->nxt;
			while ((*b)->num != max && tmp && tmp->num == max)
				pick_case(a, b, SB, v);
			while (((*b)->num != max) && *b)
				normalize_b(a, b, v, max);
			while (*b && (*b)->num == max)
			{
				tmp = *b;
				pick_case(a, b, PA, v);
				max = get_max(*b);
				free(tmp);
			}
		}
	}
}

void	sort_bigger(t_stk **a, t_stk **b, int len, t_var *v)
{
	int	max;

	max = 0;
	first_sort(a, b, len, v);
	second_sort(a, b, len, v);
	third_sort(a, b, max, v);
	free_stk(a);
	free_stk(b);
}
