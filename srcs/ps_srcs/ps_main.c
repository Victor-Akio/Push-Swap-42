/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 04:53:08 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/19 20:02:46 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	push_swap(t_var *v)
{
	if (sort_verify(v) == 1)
		return ;
	if (v->size == 2)
		ft_ptwo(v->stack_a, v->size, 1);
	else if (v->size == 3)
		ft_pthree(v->stack_a, v->size, 1);
	else if (v->size <= 6)
		ft_psix(v, v->size);
	else
		ft_pbigger(v, v->size);
	// if (sort_verify(v) == 0)
	// 	push_swap(v);
}

void	print_stk(int *stk, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%i ", stk[i]);
		fflush(stdout);
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_var		v;
	char		**args;
	int			x;

	x = 0;
	if (ac < 2)
		ft_exit("ERROR: no arguments\n", 2);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (0);
	}
	else
		args = av + 1;
	if (args_struct(&v, args) == 0)
		ft_exit("ERROR - Couldn't start.\n", 2);
	push_swap(&v);
	print_stk(v.stack_a, v.size);
	free(v.stack_a);
	free(v.stack_b);
	return (0);
}
