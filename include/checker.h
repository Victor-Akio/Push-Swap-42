/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:22:35 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 21:54:58 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include "libft.h"

char			**set_args(int ac, char **av, t_var *v);
void			check_overflow(char **args);
void			first_check(t_var *v);
int				last_check(t_var *v);
void			checker(t_var *v);
int				ft_isvalid(char *s);
void			exec_action(t_var *v, char *act);
void			ft_print_movements(int n);
void			ft_printboth(t_var *v, int i);
void			ft_putstack(t_var *v);
int				add_elem(t_var *v, char stk, int elem);
/*
** Swap functions
*/
void			swap_sab(int *stk, int size);
void			swap_ss(t_var *v);
int				swap_pa(t_var *v);
int				swap_pb(t_var *v);
void			swap_rr(t_var *v);
void			swap_rab(int *stk, int size);
void			swap_rrr(t_var *v);
void			swap_rrab(int *stk, int size);

#endif