/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:09:11 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 23:57:02 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		max;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i >= ft_abs(len / 4))
	{
		tmp1 = ft_lst_dup(*a);
		max = get_pivot(tmp1);
		while (check_pivot((*a), max, 1) && (*a))
		{
			if ((*a)->num <= max)
			{
				tmp2 = *a;
				pick_case(a, b, PB, v);
				i--;
				free(tmp2);
			}
			else
				normalize_fc(a, b, v, max);
		}
		free_stk(&tmp1);
	}
}

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
				normalize_fc(a, b, v, min);
		}
	}
}

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
				normalize_tc(a, b, v, max);
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
