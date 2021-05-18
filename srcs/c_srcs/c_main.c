/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 06:11:16 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/05 01:42:35 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isvalid(char *s)
{
	return (ft_strcmp(s, "sa") == 0
		|| ft_strcmp(s, "sb") == 0
		|| ft_strcmp(s, "ss") == 0
		|| ft_strcmp(s, "pa") == 0
		|| ft_strcmp(s, "pb") == 0
		|| ft_strcmp(s, "ra") == 0
		|| ft_strcmp(s, "rb") == 0
		|| ft_strcmp(s, "rr") == 0
		|| ft_strcmp(s, "rra") == 0
		|| ft_strcmp(s, "rrb") == 0
		|| ft_strcmp(s, "rrr") == 0
		|| ft_strcmp(s, "q") == 0);
}

void	checker(t_var *v)
{
	int			nxt;
	static int	index;
	char		*action;

	index = 0;
	nxt = 1;
	while (nxt > 0)
	{
		if (v->flag_v == 1)
			ft_putstack(v);
		nxt = get_next_line(0, &action);
		if (nxt != 0 && ft_isvalid(action) == 0)
		{
			free(action);
			ft_exit("ERROR - Invalid Command.\n", 2);
		}
		if (nxt != 0)
		{
			index++;
			exec_action(v, action);
			free(action);
		}
	}
	if (v->flag_c == 1)
		ft_print_movements(index);
}

void	initialize(t_var *v)
{
	v->size = 0;
	v->len_a = 0;
	v->len_b = 0;
	v->flag_v = 0;
	v->flag_c = 0;
}

int	main(int ac, char **av)
{
	t_var	v;
	char	**args;

	initialize(&v);
	args = set_args(ac, av, &v);
	check_overflow(args);
	if (args_struct(&v, args) == 0)
		ft_exit("ERROR - Could not build stack.\n", 2);
	first_check(&v);
	checker(&v);
	last_check(&v);
	free(v.stack_a);
	free(v.stack_b);
	return (0);
}
