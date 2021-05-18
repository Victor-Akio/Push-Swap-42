/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:44:51 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 21:56:11 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	ft_rrab(int *stk, int len, int ab)
{
	int		i;
	int		tmp;

	if (ab == 1)
		ft_putstr_fd("rra\n", 1);
	else if (ab == 2)
		ft_putstr_fd("rrb\n", 1);
	i = len - 1;
	tmp = stk[len - 1];
	while (i > 0)
	{
		stk[i] = stk[i - 1];
		i--;
	}
	stk[0] = tmp;
}

void	ft_rrr(t_var *v)
{
	ft_putstr_fd("rrr\n", 1);
	ft_rrab(v->stack_a, v->len_a, 0);
	ft_rrab(v->stack_b, v->len_b, 0);
}
