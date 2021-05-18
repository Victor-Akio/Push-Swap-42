/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 05:14:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/15 21:24:35 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

typedef struct s_big
{
	int		i;
	int		j;
	int		p1;
	int		p2;
	int		p3;
	int		p4;
	int		p5;
	int		len1;
	int		len2;
	int		len3;
	int		len4;
	int		min;
	int		max;
	int		flag;
	int		new1;
	int		new2;
	int		len_new;
	int		dist;
	int		dist_min;
	int		dist_max;
	int		dir;
	int		small;
	int		big;
}	t_big;

void			init_big(t_big *b);
void			init_reset(t_big *b, int len, int x, int y);

int				sort_verify(t_var *v);
int				find_min(int *stk, int n);
int				find_max(int *stk, int n);
void			find_maxmin(int x, t_big *b);
void			ft_sort(t_var *v, int n, t_big *b);
int				add_elem(t_var *v, char stk, int elem);

void			ft_rr(t_var *v);
void			ft_ss(t_var *v);
void			ft_rab(int *stk, int len, int ab);
void			ft_sab(int *stk, int len, int ab);
int				ft_pb(t_var *v);
int				ft_pa(t_var *v);
void			ft_rrab(int *stk, int len, int ab);
void			ft_rrr(t_var *v);

void			ft_psix(t_var *v, int n);
void			ft_pthree(int *stk, int n, int ab);
void			ft_ptwo(int *stk, int n, int ab);
void			ft_pbigger(t_var *v, int n);

#endif