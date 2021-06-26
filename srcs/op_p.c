/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 03:30:41 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 01:13:39 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This file has the operations regardin pushing items between stacks;
** 'pa' 'pb'
*/
void	p_stk(t_stk **a, t_stk **b, t_stk *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_stk *)malloc(sizeof(t_stk));
		(*b)->prv = NULL;
		(*b)->num = (*a)->num;
		(*b)->nxt = NULL;
		(*a) = (*a)->nxt;
		(*a)->prv = NULL;
	}
	else
	{
		if (*a)
		{
			tmp = (t_stk *)malloc(sizeof(t_stk));
			tmp->num = (*a)->num;
			tmp->nxt = NULL;
			tmp->prv = NULL;
			add_front(b, tmp);
			(*a) = (*a)->nxt;
		}
	}
}
