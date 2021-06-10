/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 22:53:52 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 22:46:46 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_fc(t_stk **a, t_stk **b, t_var *v, int max)
{
	int	idx;
	int	half;

	idx = get_idx((*a), max, 1);
	half = (list_size((*a)) / 2);
	if (half > idx)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

void	normalize_tc(t_stk **a, t_stk **b, t_var *v, int max)
{
	int	idx;
	int	half;

	idx = get_idx((*b), max, 2);
	half = ft_abs((list_size((*b)) / 2));
	if (half > idx && *b)
		pick_case(a, b, RB, v);
	else if (*b)
		pick_case(a, b, RRB, v);
}
