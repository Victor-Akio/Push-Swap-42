/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap_rab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:12:31 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:50:07 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_rab(int *stk, int size)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stk[0];
	while (i < size - 1)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[size - 1] = tmp;
}

void	swap_rr(t_var *v)
{
	swap_rab(v->stack_a, v->len_a);
	swap_rab(v->stack_b, v->len_b);
}
