/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:30:28 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/23 03:43:14 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	*ft_init_var(t_var *v)
{
	v = (t_var *)malloc(sizeof(t_var));
	if (v == NULL)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->len = 0;
	v->line = NULL;
	v->split = NULL;
	v->print = 0;
	return (v);
}
