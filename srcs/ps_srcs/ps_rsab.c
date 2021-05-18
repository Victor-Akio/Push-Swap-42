/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rsab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:54:52 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 22:03:05 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	ft_rab(int *stk, int len, int ab)
{
	int		i;
	int		tmp;

	if (ab == 1)
		ft_putstr_fd("ra\n", 1);
	else if (ab == 2)
		ft_putstr_fd("rb\n", 1);
	i = 0;
	tmp = stk[0];
	while (i < len - 1)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[len - 1] = tmp;
}

void	ft_rr(t_var *v)
{
	ft_putstr_fd("rr\n", 1);
	ft_rab(v->stack_a, v->len_a, 0);
	ft_rab(v->stack_b, v->len_b, 0);
}

void	ft_sab(int *stk, int len, int ab)
{
	int		x;

	if (ab == 1)
		ft_putstr_fd("sa\n", 1);
	else if (ab == 2)
		ft_putstr_fd("sb\n", 1);
	if (len >= 2)
	{
		x = stk[0];
		stk[0] = stk[1];
		stk[1] = x;
	}
}

void	ft_ss(t_var *v)
{
	ft_putstr_fd("ss\n", 1);
	ft_sab(v->stack_a, v->len_a, 0);
	ft_sab(v->stack_b, v->len_b, 0);
}
