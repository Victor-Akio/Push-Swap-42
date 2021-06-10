/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 05:39:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/10 23:57:09 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

char	**fill_args(t_var *v, int ac, char **av)
{
	v->fd = 1;
	if (ac == 2)
		v->split = ft_split(av[1], ' ');
	else
		v->split = &av[1];
	return (v->split);
}

void	push_swap(t_var *v, int ac, char **av)
{
	t_stk	*stk;

	stk = NULL;
	v->split = fill_args(v, ac, av);
	check_dup(v->split);
	check_numbers(v->split);
	v->a = fill_list(v, v->split, stk);
	if (check_sort(&v->a, list_size(v->a)) == 1)
		ft_exit("ERROR - invalid list of arguments.\n", 0);
	v->len = list_size(v->a);
	free_stk(&stk);
	if (v->len <= 10)
		sort_short(&(v->a), &(v->b), v->len, v);
	else
		sort_bigger(&(v->a), &(v->b), v->len, v);
	if (ac == 2 || (ac ==3 && v->fd != 1))
		ft_free_array(v->split);
	close(v->fd);
}

void	ft_help(void)
{
	ft_putstr_fd("Push_Swap: How to ...\n", 1);
	ft_putstr_fd("To run the program, please use...\n", 1);
	ft_putstr_fd("./push_swap \"Number sequence\"\n", 1);
}

int	main(int ac, char **av)
{
	t_var	*v;

	v = NULL;
	if (ac < 2)
		ft_exit("Wrong number of arguments", 1);
	else
	{
		v = ft_init_var(v);
		if (!ft_strcmp(av[1], "-h"))
			ft_help();
		else
			push_swap(v, ac, av);
		free(v);
		v = NULL;
	}
}
