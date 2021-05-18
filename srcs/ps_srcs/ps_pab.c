/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 21:32:11 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 18:04:58 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int	ft_pb(t_var *v)
{
	int		*tmp;

	tmp = 0;
	ft_putstr_fd("pb\n", 1);
	if (v->len_a > 1)
	{
		tmp = malloc(sizeof(int) * (v->len_a));
		ft_intcpy(v->stack_a + 1, tmp, v->len_a - 1);
		if (!tmp || !(add_elem(v, 'b', v->stack_a[0])))
			return (0);
		v->len_a--;
		free(v->stack_a);
		v->stack_a = tmp;
	}
	else if (v->len_a == 1)
	{
		tmp = malloc(sizeof(int) * 1);
		if (!tmp || !(add_elem(v, 'b', v->stack_a[0])))
			return (0);
		v->len_a--;
		free(v->stack_a);
		v->stack_a = tmp;
	}
	return (1);
}

int	ft_pa(t_var *v)
{
	int		*tmp;

	tmp = 0;
	ft_putstr_fd("pa\n", 1);
	if (v->len_b > 1)
	{
		tmp = malloc(sizeof(int) * (v->len_b - 1));
		ft_intcpy(v->stack_b + 1, tmp, v->len_b - 1);
		if (!tmp || !(add_elem(v, 'a', v->stack_b[0])))
			return (0);
		v->len_b--;
		free(v->stack_b);
		v->stack_b = tmp;
	}
	else if (v->len_b == 1)
	{
		tmp = malloc(sizeof(int) * 1);
		if (!tmp || !(add_elem(v, 'a', v->stack_b[0])))
			return (0);
		v->len_b--;
		free(v->stack_b);
		v->stack_b = tmp;
	}
	return (1);
}
