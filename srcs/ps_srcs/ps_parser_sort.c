/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:27:21 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 22:24:56 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	ft_sort3(t_var *v, t_big *b)
{
	if (b->dir == 1)
	{
		while (b->dist > 0)
		{
			ft_rab(v->stack_b, v->len_b, 2);
			b->dist--;
		}
		ft_pa(v);
	}
	else
	{
		while (b->dist > 0)
		{
			ft_rrab(v->stack_a, v->len_a, 2);
			b->dist--;
		}
		ft_pa(v);
	}
	b->big++;
}

void	ft_sort2(t_var *v, t_big *b)
{
	if (b->flag == 1)
	{
		if (b->dir == 1)
		{
			while (b->dist > 0)
			{
				ft_rab(v->stack_b, v->len_b, 2);
				b->dist--;
			}
			ft_pa(v);
			ft_rab(v->stack_a, v->len_a, 1);
		}
		else
		{
			while (b->dist > 0)
			{
				ft_rrab(v->stack_b, v->len_b, 2);
				b->dist--;
			}
			ft_pa(v);
			ft_rab(v->stack_a, v->len_a, 1);
		}
	}
	else
		ft_sort3(v, b);
}

void	ft_sort(t_var *v, int n, t_big *b)
{
	while (b->i < n && v->len_b <= b->len_new)
	{
		if (v->stack_a[0] >= b->new1 && v->stack_a[0] < b->new2)
			ft_pb(v);
		else
			ft_rab(v->stack_a, v->len_a, 1);
		b->i++;
	}
	while (v->len_b > 0)
	{
		b->min = find_min(v->stack_b, v->len_b);
		b->max = find_max(v->stack_b, v->len_b);
		find_maxmin(v->len_b, b);
		ft_sort2(v, b);
	}
	while (b->big-- > 0)
		ft_rab(v->stack_a, v->len_a, 1);
}
