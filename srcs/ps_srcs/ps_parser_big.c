/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:22:09 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/18 22:31:15 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	parse_maxmin(int l, t_big *b, int min, int max)
{
	if (min <= max)
	{
		b->flag = 1;
		b->dist = min;
		if (b->min <= l / 2)
			b->dir = 1;
		else
			b->dir = -1;
	}
	else
	{
		b->flag = 2;
		b->dist = max;
		if (b->max <= l / 2)
			b->dir = 1;
		else
			b->dir = -1;
	}
}

void	find_maxmin(int l, t_big *b)
{
	int		min;
	int		max;

	if (b->min <= l / 2)
		min = b->min;
	else
		min = l - b->min;
	if (b->max <= l / 2)
		max = b->max;
	else
		max = l - b->max;
	parse_maxmin(l, b, min, max);
}

void	sort_blocks(int *sort, int len, t_big *b)
{
	b->p0 = sort[0];
	b->p1 = sort[len / 4];
	b->len1 = len / 4;
	b->p2 = sort[len / 2];
	b->len2 = (len / 2) - (len / 4);
	b->p3 = sort[len / 4 * 3];
	b->len3 = (len / 4 * 3) - (len / 2);
	b->p4 = sort[len - 1];
	b->len4 = (len - 1) - (len / 4 * 3);
}

void	ft_pbigger(t_var *v, int n)
{
	t_big	b;
	int		*sort;

	init_big(&b);
	sort = ft_sort_nbr(v->stack_a, v->len_a);
	sort_blocks(sort, v->len_a, &b);
	b.len_new = b.len1;
	b.new1 = b.p0;
	b.new2 = b.p1;
	ft_sort(v, n, &b);
	init_reset(&b, b.len2, b.p1, b.p2);
	ft_sort(v, n, &b);
	init_reset(&b, b.len3, b.p2, b.p3);
	ft_sort(v, n, &b);
	init_reset(&b, b.len4, b.p3, b.p4 + 1);
	ft_sort(v, n, &b);
	// init_reset(&b, b.len_new, b.p2, b.p5 + 1);
	// ft_sort(v, n, &b);
	free(sort);
}
