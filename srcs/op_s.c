/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:40:14 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 01:17:12 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This file has the functions related to the swap operations;
** 'sa' 'sb'
*/
void	s_stk(t_stk **top)
{
	int		i;
	int		j;
	t_stk	*tmp;

	tmp = NULL;
	if ((*top) && (*top)->nxt)
	{
		tmp = *top;
		i = (*top)->num;
		j = (*top)->nxt->num;
		tmp = *top;
		(*top)->num = j;
		tmp = *top;
		(*top)->nxt->num = i;
		(*top) = tmp;
	}
}
