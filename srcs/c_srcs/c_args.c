/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:08:49 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 21:32:11 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_flags(char *flag, t_var *v)
{
	int		i;

	i = 1;
	while (flag[i])
	{
		if (flag[i] == 'v')
			v->flag_v = 1;
		else if (flag[i] == 'c')
			v->flag_c = 1;
		else
			return ;
		i++;
	}
}

char	**set_args_cont(char **av, t_var *v)
{
	char	**args;

	if (av[1][0] == '-')
	{
		set_flags(av[1], v);
		args = av + 2;
	}
	else
		args = av + 1;
	return (args);
}

static void	if_three(char **av, t_var *v, char **args)
{
	if (av[1][0] == '-')
	{
		set_flags(av[1], v);
		args = ft_split(av[2], ' ');
		if (!args)
			ft_exit("ERROR: split-malloc error\n", 2);
	}
	else
		args = av + 1;
}

char	**set_args(int ac, char **av, t_var *v)
{
	char	**args;

	args = NULL;
	if (ac < 2)
		ft_exit("ERROR: No arguments found.\n", 2);
	else if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			ft_exit("ERROR: split-malloc error\n", 2);
	}
	else if (ac == 3)
		if_three(av, v, args);
	else
		args = set_args_cont(av, v);
	return (args);
}
