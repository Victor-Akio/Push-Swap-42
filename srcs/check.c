/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:26:56 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/28 21:17:55 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check_sort - will validate if the list is correctly populated;
*/
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

/*
** Check_dup - check if there is any duplicated numbers within the list
*/
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
				ft_exit_ps("Error - duplicated values.\n", 1);
			}
			else
				j++;
		}
		ft_free_arg(&dup);
		i++;
	}
}

/*
** This function will check if there is any overflow.
*/
int	check_overflow(char *arg)
{
	long long	tmp;

	tmp = ps_atoll(arg);
	if (tmp >= INT_MIN && tmp <= INT_MAX && ft_strlen(arg) < 12)
		return (1);
	return (0);
}

/*
** Check_numbers will validate if all arguments are numbers
*/
int	check_numbers(char **av)
{
	int		i;
	int		j;

	i = -1;
	if (!av[0])
		ft_exit_ps("Error - no int found in args.\n", 1);
	while (av[++i])
	{
		j = -1;
		if (check_overflow(av[i]) == 0)
			ft_exit_ps("Error - Int Overflow.\n", 1);
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.'
			|| ((av[i][j]) == '-' && (av[i][j +1]) == '\0')
			|| ((av[i][j]) == '+' && (av[i][j +1]) == '\0'))
				ft_exit_ps("Error - Not valid input in arg.\n", 1);
		}
	}
	return (1);
}

/*
** Check_pivot - is responsible to find if flag is '1', related to the stack a
** where it is important to know if the number is lower or equals to the pivot
**
** If flag '2', you intend to check if the number is the pivot selected;
*/
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
