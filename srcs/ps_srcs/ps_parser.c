/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 06:42:29 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 20:52:28 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	ft_psix(t_var *v, int n)
{
	int		i;

	i = -1;
	while (++i < n - 3)
		ft_pb(v);
	ft_pthree(v->stack_a, 3, 1);
	if (n == 5)
		ft_ptwo(v->stack_b, n - 3, 2);
	else
		ft_pthree(v->stack_b, n - 3, 2);
	while (v->len_b > 0)
	{
		if (v->stack_b[0] <= v->stack_a[0])
			ft_pa(v);
		else if (v->stack_b[0] >= v->stack_a[0]
			&& v->stack_b[0] >= v->stack_a[v->len_a - 1]
			&& v->stack_a[0] <= v->stack_a[1]
			&& v->stack_a[0] <= v->stack_a[v->len_a - 1])
			ft_pa(v);
		else
			ft_rab(v->stack_a, v->len_a, 1);
	}
	while (!(v->stack_a[0] <= v->stack_a[1]
			&& v->stack_a[0] <= v->stack_a[v->len_a - 1]))
		ft_rab(v->stack_a, v->len_a, 1);
}

void	ft_pthree(int *stk, int n, int ab)
{
	int		a;
	int		b;
	int		c;

	a = stk[0];
	b = stk[n - 1];
	c = stk[1];
	if (a > c && a < b)
		ft_sab(stk, n, ab);
	else if (a > c && a > c && c > b)
	{
		ft_sab(stk, n, ab);
		ft_rrab(stk, n, ab);
	}
	else if (a > c && a > b && c < b)
		ft_rab(stk, n, ab);
	else if (a < c && c > b && a < b)
	{
		ft_sab(stk, n, ab);
		ft_rab(stk, n, ab);
	}
	else if (a < c && c > b && a > b)
		ft_rrab(stk, n, ab);
}

void	ft_ptwo(int *stk, int n, int ab)
{
	int		x;
	int		y;

	x = stk[0];
	y = stk[n -1];
	if (x > y)
		ft_sab(stk, n, ab);
}

int	sort_verify(t_var *v)
{
	int		i;

	i = 0;
	if (v->len_a != v->size)
		return (0);
	while (i < v->len_a - 1)
	{
		if (v->stack_a[i] == v->stack_a[i + 1])
		{
			free(v->stack_a);
			free(v->stack_b);
			ft_exit("Error - duplicated value", 2);
		}
		if (v->stack_a[i] > v->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
