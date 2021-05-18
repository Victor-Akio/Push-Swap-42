/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap_pab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:46:03 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/05 01:50:01 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	*malloc_lenab(int *new, int len)
{
	new = malloc(sizeof(int) * (len));
	if (!new)
		return (0);
	return (new);
}

int	swap_pa(t_var *v)
{
	int		*new;

	new = NULL;
	if (v->len_b > 1)
	{
		new = malloc_lenab(new, v->len_b - 1);
		ft_intcpy(v->stack_b + 1, new, v->len_b - 1);
		if (!(add_elem(v, 'a', v->stack_b[0])))
			return (0);
		v->len_b--;
		free(v->stack_b);
		v->stack_b = new;
	}
	else if (v->len_b == 1)
	{
		new = malloc_lenab(new, 1);
		if (!(add_elem(v, 'a', v->stack_b[0])))
			return (0);
		v->len_b--;
		free(v->stack_b);
		v->stack_b = new;
	}
	return (1);
}

int	swap_pb(t_var *v)
{
	int		*new;

	new = NULL;
	if (v->len_a > 1)
	{
		new = malloc_lenab(new, v->len_a - 1);
		ft_intcpy(v->stack_a + 1, new, v->len_a - 1);
		if (!(add_elem(v, 'b', v->stack_a[0])))
			return (0);
		v->len_a--;
		free(v->stack_a);
		v->stack_a = new;
	}
	else if (v->len_a == 1)
	{
		new = malloc_lenab(new, 1);
		if (!(add_elem(v, 'b', v->stack_a[0])))
			return (0);
		v->len_a--;
		free(v->stack_a);
		v->stack_a = new;
	}
	return (1);
}
