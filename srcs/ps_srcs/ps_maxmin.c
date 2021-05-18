/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_maxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:20:43 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 22:49:15 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int	find_max(int *stk, int n)
{
	int		i;
	int		index;
	int		max;

	i = 0;
	index = 0;
	max = stk[0];
	while (i < n)
	{
		if (stk[i] > max)
		{
			index = i;
			max = stk[i];
		}
		i++;
	}
	return (index);
}

int	find_min(int *stk, int n)
{
	int		i;
	int		index;
	int		min;

	i = 0;
	index = 0;
	min = stk[0];
	while (i < n)
	{
		if (stk[i] < min)
		{
			index = i;
			min = stk[i];
		}
		i++;
	}
	return (index);
}
