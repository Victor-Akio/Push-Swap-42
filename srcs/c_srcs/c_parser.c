/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:34:54 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:48:20 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	last_check(t_var *v)
{
	int		i;

	i = 0;
	if (v->len_a != v->size)
	{
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
	while (i < v->len_a - 1)
	{
		if (v->stack_a[i] == v->stack_a[i + 1])
		{
			free(v->stack_a);
			free(v->stack_b);
			ft_exit("ERROR - Duplicated args.\n", 2);
		}
		if (v->stack_a[i] > v->stack_a[i + 1])
		{
			ft_putstr_fd("KO\n", 1);
			return (0);
		}
		i++;
	}
	ft_putstr_fd("OK\n", 1);
	return (1);
}

void	check_duplicates(t_var *v)
{
	int		i;

	i = 0;
	while (i < v->len_a - 1)
	{
		if (v->stack_a[i] == v->stack_a[i + 1])
		{
			free(v->stack_a);
			free(v->stack_b);
			ft_exit("ERROR - Duplicated numbers.\n", 2);
		}
		i++;
	}
}

void	first_check(t_var *v)
{
	int		*sort;

	sort = ft_sort_nbr(v->stack_a, v->len_a);
	check_duplicates(v);
	free(sort);
}

void	check_overflow(char **args)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		if (ft_strlen(args[i]) > ft_strlen("-2147483648"))
			ft_exit("ERROR - Possible integer overflow.\n", 2);
		else if (ft_strlen(args[i]) == ft_strlen("-2147483648"))
		{
			if (args[i][0] != '-' || args[i][0] != '+')
				ft_exit("ERROR - Invalid Argument.\n", 2);
			else
			{
				if (ps_atoll(args[i]) > INT_MAX || ps_atoll(args[i]) < INT_MIN)
					ft_exit("ERROR - Integer overflow.\n", 2);
			}
		}
	}
}

void	exec_action(t_var *v, char *act)
{
	if (ft_strcmp(act, "sa") == 0)
		swap_sab(v->stack_a, v->len_a);
	else if (ft_strcmp(act, "sb") == 0)
		swap_sab(v->stack_b, v->len_b);
	else if (ft_strcmp(act, "ss") == 0)
		swap_ss(v);
	else if (ft_strcmp(act, "pa") == 0)
		swap_pa(v);
	else if (ft_strcmp(act, "pb") == 0)
		swap_pb(v);
	else if (ft_strcmp(act, "ra") == 0)
		swap_rab(v->stack_a, v->len_a);
	else if (ft_strcmp(act, "rb") == 0)
		swap_rab(v->stack_b, v->len_b);
	else if (ft_strcmp(act, "rr") == 0)
		swap_rr(v);
	else if (ft_strcmp(act, "rra") == 0)
		swap_rrab(v->stack_a, v->len_a);
	else if (ft_strcmp(act, "rrb") == 0)
		swap_rrab(v->stack_b, v->len_b);
	else if (ft_strcmp(act, "rrr") == 0)
		swap_rrr(v);
}
