/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:49:21 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 01:57:52 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The index number will act as base paramenter to rotate numbers in two 
** situations. Flag '1' will occur when the number you want to know the lower
** number in the stack, Flag '2' will occur when you want to set the maximun
** number to the index.
*/
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

/*
** After some research and testing, there is a range of 
** efficiency when it comes to the size of the lists analyzed
** 
*/
int	get_pivot(t_stk *stk)
{
	t_stk	*tmp;
	int		len;
	int		pvt;

	pvt = 0;
	len = 0;
	tmp = NULL;
	len = list_size(stk);
	tmp = ft_lstsort(stk);
	if (len <= 10)
		pvt = ft_abs(len / 2);
	else if (len > 10 && len < 200)
		pvt = ft_abs(len / 4);
	else if (len >= 200)
		pvt = ft_abs(len / 8);
	return (ft_lstnbr(&tmp, pvt));
}

/*
** This function will pass through the stack to find the maximum
** number in the stack.
*/
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

/*
** This function will pass through the stack to find the minimum
** number in the stack.
*/
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
