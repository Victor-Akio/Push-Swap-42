/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_u2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:44:55 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 01:31:12 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function will duplicate the list;
** Returning the duplicated list;
*/
t_stk	*ft_lst_dup(t_stk *stk)
{
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = malloc(sizeof(t_stk));
	ft_bzero(tmp1, sizeof(t_stk));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->num = stk->num;
		if (stk->nxt)
		{
			tmp1->nxt = malloc(sizeof(t_stk));
			ft_bzero(tmp1->nxt, sizeof(t_stk));
			tmp1 = tmp1->nxt;
		}
		stk = stk->nxt;
	}
	tmp1 = tmp2;
	return (tmp1);
}

/*
** Find the bottom number of the list
*/
t_stk	*ft_lst_bottom(t_stk *a)
{
	t_stk	*tmp;

	tmp = a;
	while ((tmp)->nxt)
		(tmp) = (tmp)->nxt;
	return (tmp);
}
