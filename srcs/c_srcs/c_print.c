/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 06:26:00 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:47:57 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_movements(int n)
{
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(" movements to sort array.\n", 1);
}

void	ft_printboth(t_var *v, int i)
{
	ft_putnbr_fd(v->stack_a[i], 1);
	ft_putstr_fd(" || ", 1);
	ft_putnbr_fd(v->stack_b[i], 1);
	ft_putchar_fd(10, 1);
}

void	ft_putstack(t_var *v)
{
	int		i;

	i = -1;
	ft_putstr_fd("STACK A || STACK B\n", 1);
	while (++i < v->len_a || i < v->len_b)
	{
		if (i < v->len_a && i < v->len_b)
		{
			ft_printboth(v, i);
		}
		else if (i < v->len_a)
		{
			ft_putnbr_fd(v->stack_a[i], 1);
			ft_putendl_fd(" ||", 1);
		}
		else if (i < v->len_b)
		{
			ft_putstr_fd("   || ", 1);
			ft_putnbr_fd(v->stack_b[i], 1);
			ft_putchar_fd(10, 1);
		}
	}
	ft_putchar_fd(10, 1);
}
