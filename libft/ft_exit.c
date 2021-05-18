/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:11:19 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:42:03 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	else
		ft_putstr_fd("exit\n", 1);
	exit(err);
}
