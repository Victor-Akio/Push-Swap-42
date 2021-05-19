/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:27:51 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/18 22:01:52 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	init_reset(t_big *b, int len, int x, int y)
{
	b->i = 0;
	b->j = 0;
	b-> min = 0;
	b-> max = 0;
	b->dist = 0;
	b->dist_min = 0;
	b->dist_max = 0;
	b->dir = 0;
	b->flag = 0;
	b->small = 0;
	b->big = 0;
	b->len_new = len;
	b->new1 = x;
	b->new2 = y;
}

void	init_big(t_big *b)
{
	b->i = 0;
	b->j = 0;
	b->p1 = 0;
	b->p2 = 0;
	b->p3 = 0;
	b->p4 = 0;
	b->min = 0;
	b->max = 0;
	b->flag = 0;
	b->dist = 0;
	b->dist_min = 0;
	b->dist_max = 0;
	b->dir = 0;
	b->small = 0;
	b->big = 0;
}
