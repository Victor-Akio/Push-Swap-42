/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:59:28 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 22:42:06 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstnbr(t_stk **stk, int idx)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (i == idx)
			return (tmp->num);
		i++;
		tmp = tmp->nxt;
	}
	return (1);
}

void	ft_lstswp(t_stk *x, t_stk *y)
{
	int	tmp;

	tmp = x->num;
	x->num = y->num;
	y->num = tmp;
}

t_stk	*ft_lstsort(t_stk *stk)
{
	t_stk	*from;
	t_stk	*tmp;
	t_stk	*min;

	from = NULL;
	from = stk;
	tmp = NULL;
	min = NULL;
	while (from->nxt)
	{
		min = from;
		tmp = from->nxt;
		while (tmp)
		{
			if (min->num > tmp->num)
				min = tmp;
			tmp = tmp->nxt;
		}
		ft_lstswp(from, min);
		from = from->nxt;
	}
	return (stk);
}
