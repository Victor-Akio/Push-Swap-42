/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap_sab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:40:02 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:49:48 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_sab(int *stk, int size)
{
	int		tmp;

	if (size >= 2)
	{
		tmp = stk[0];
		stk[0] = stk[1];
		stk[1] = tmp;
	}
}

void	swap_ss(t_var *v)
{
	swap_sab(v->stack_a, v->len_a);
	swap_sab(v->stack_b, v->len_b);
}
