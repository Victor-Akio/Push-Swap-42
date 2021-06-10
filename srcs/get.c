/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:49:21 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 22:44:37 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_idx(t_stk *stk, int num, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		while (stk)
		{
			if (stk->num <= num)
				return (i);
			stk = stk->nxt;
			i++;
		}
	}
	if (flag == 2)
	{
		while (stk)
		{
			if (stk->num >= num)
				return (i);
			stk = stk->nxt;
			i++;
		}
	}
	return (-1);
}

int	get_pivot(t_stk *stk)
{
	t_stk	*tmp;
	int		len;
	int		max;

	max = 0;
	len = 0;
	tmp = NULL;
	len = list_size(stk);
	tmp = ft_lstsort(stk);
	if (len <= 12)
		max = ft_abs(len / 2);
	else if (len > 12 && len < 200)
		max = ft_abs(len / 4);
	else if (len >= 200)
		max = ft_abs(len / 8);
	return (ft_lstnbr(&tmp, max));
}

int	get_max(t_stk *stk)
{
	int		max;
	t_stk	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		max = stk->num;
		tmp = stk;
		while (stk)
		{
			if (stk->num >= max)
				max = stk->num;
			stk = stk->nxt;
		}
		stk = tmp;
	}
	return (max);
}

int	get_min(t_stk *stk)
{
	int	min;

	min = stk->num;
	while (stk)
	{
		if (stk->num < min)
			min = stk->num;
		stk = stk->nxt;
	}
	return (min);
}
