/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:31:37 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 20:16:03 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	add_elem(t_var *v, char stk, int elem)
{
	int		*new;

	if (stk == 'a')
	{
		new = malloc(sizeof(int) * (v->len_a + 1));
		if (!new)
			return (0);
		new[0] = elem;
		ft_intcpy(v->stack_a, new + 1, v->len_a);
		free(v->stack_a);
		v->stack_a = new;
		v->len_a++;
	}
	else if (stk == 'b')
	{
		new = malloc(sizeof(int) * (v->len_b + 1));
		if (!new)
			return (0);
		new[0] = elem;
		ft_intcpy(v->stack_b, new + 1, v->len_b);
		free(v->stack_b);
		v->stack_b = new;
		v->len_b++;
	}
	return (1);
}

int	count_args(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	return (i);
}

int	*allocate_mem(int size)
{
	int		i;
	int		*ret;

	ret = malloc(sizeof(int *) * size);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		ret[i] = 0;
	}
	return (ret);
}

int	*get_stack(int l_a, char **av)
{
	int		i;
	int		j;
	int		*ret;

	i = 0;
	j = 0;
	ret = allocate_mem(l_a);
	if (!ret)
		return (NULL);
	while (i <= l_a)
	{
		if (ft_isnbr(av[i]) == 1)
			ret[j] = ps_atoi(av[i]);
		else
		{
			free(ret);
			ft_exit("ERROR - invalid argument.\n", 2);
		}
		i++;
		j++;
	}
	return (ret);
}

int	args_struct(t_var *v, char **av)
{
	v->len_a = count_args(av);
	v->size = v->len_a;
	v->stack_a = get_stack(v->len_a - 1, av);
	if (!v->stack_a)
		ft_exit("ERROR - do not find stack.\n", 2);
	v->stack_b = allocate_mem(1);
	if (!v->stack_b)
	{
		free(v->stack_a);
		ft_exit("ERROR - Malloc error.\n", 2);
	}
	return (1);
}
