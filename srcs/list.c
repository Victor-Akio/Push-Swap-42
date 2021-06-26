/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:06:23 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 03:21:17 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*fill_list(t_var *v, char **split, t_stk *tmp)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		tmp = malloc(sizeof(t_stk));
		if (tmp == NULL)
			return (NULL);
		tmp->num = ps_atoll(split[i]);
		if (tmp->num > 2147483647 || tmp->num < -2147483648)
			ft_exit_ps("ERROR - int overflow.\n", 1);
		tmp->nxt = NULL;
		tmp->prv = NULL;
		add_back(&v->a, tmp);
		tmp = NULL;
	}
	return (v->a);
}
