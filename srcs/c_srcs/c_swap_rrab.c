/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap_rrab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:23:24 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:49:58 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_rrab(int *stk, int size)
{
	int		i;
	int		tmp;

	i = size - 1;
	tmp = stk[size -1];
	while (i > 0)
	{
		stk[i] = stk[i - 1];
		i--;
	}
	stk[0] = tmp;
}

void	swap_rrr(t_var *v)
{
	swap_rrab(v->stack_a, v->len_a);
	swap_rrab(v->stack_b, v->len_b);
}
