/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 06:27:48 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/25 22:37:14 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getnbr(char const *str)
{
	int		nbr;
	int		neg;

	nbr = 0;
	neg = 0;
	if (*str == '-')
	{
		str++;
		neg++;
	}
	while (*str)
	{
		nbr *= 10;
		nbr = (*str - 48) + nbr;
		str++;
	}
	if (neg)
		nbr *= -1;
	return (nbr);
}
