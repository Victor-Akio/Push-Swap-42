/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:26:56 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 22:42:48 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stk **a, int len)
{
	t_stk	*tmp;

	if (list_size(*a) != len)
		return (0);
	(void)len;
	tmp = *a;
	while (tmp && tmp->nxt)
	{
		if ((tmp)->nxt != NULL && ((tmp)->num < (tmp)->nxt->num))
			(tmp) = tmp->nxt;
		else
			return (0);
	}
	return (1);
}

void	check_dup(char **av)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (av[i])
	{
		dup = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(dup, av[j]) == 0)
			{
				ft_free_arg(&dup);
				ft_exit("ERROR - duplicated values.\n", 1);
			}
			else
				j++;
		}
		ft_free_arg(&dup);
		i++;
	}
}

int	check_numbers(char **av)
{
	int		i;
	int		j;

	i = -1;
	if (!av[0])
		ft_exit("ERROR - no int found in args.\n", 1);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.'
			|| ((av[i][j]) == '-' && (av[i][j +1]) == '\0')
			|| ((av[i][j]) == '+' && (av[i][j +1]) == '\0'))
				ft_exit("Error - Not valid input in arg.\n", 1);
		}
	}
	return (1);
}

int	check_pivot(t_stk *a, int pvt, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->num <= pvt)
				return (1);
			a = a->nxt;
		}
		if (flag == 2)
		{
			if (a->num == pvt)
				return (1);
			a = a->nxt;
		}
	}
	return (0);
}
