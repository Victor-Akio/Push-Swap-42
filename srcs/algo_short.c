/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:04:45 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 23:57:20 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm(t_stk **a, t_stk **b, t_var *v, int min)
{
	int	idx;
	int	num;

	idx = get_idx((*a), min, 1);
	num = (list_size((*a)) / 2);
	if (num > idx)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

void	sort_min_10(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		min;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->nxt;
		if ((*a)->num != min && tmp1 && tmp1->num == min)
			pick_case(a, b, SA, v);
		while (min != (*a)->num)
			norm(a, b, v, min);
		if (min == (*a)->num)
		{
			tmp2 = *a;
			pick_case(a, b, PB, v);
			free(tmp2);
			i--;
		}
	}
}

void	sort_3(t_stk **a, t_stk **b, t_var *v, int op)
{
	pick_case(a, b, SA, v);
	pick_case(a, b, op, v);
}

void	case_with_3(t_stk **a, t_stk **b, int len, t_var *v)
{
	t_stk	*tmp;
	int		min;

	tmp = ft_lst_bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->num < (*a)->nxt->num && tmp->num == min)
			pick_case(a, b, RRA, v);
		else if ((*a)->num > (*a)->nxt->num && tmp->num == min)
			sort_3(a, b, v, RRA);
		else if ((*a)->nxt->num == min)
		{
			if ((*a)->num < tmp->num)
				pick_case(a, b, SA, v);
			else if ((*a)->num > tmp->num)
				pick_case(a, b, RA, v);
		}
		else if ((*a)->num == min && (*a)->nxt->num > tmp->num)
			sort_3(a, b, v, RA);
	}
}

void	sort_short(t_stk **a, t_stk **b, int len, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->num > (*a)->nxt->num)
		pick_case(a, b, SA, v);
	if (len <= 3)
		case_with_3(a, b, len, v);
	else if (len > 3)
	{
		sort_min_10(a, b, len, v);
		case_with_3(a, b, 3, v);
		while ((*b))
		{
			tmp = *b;
			pick_case(a, b, PA, v);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}
