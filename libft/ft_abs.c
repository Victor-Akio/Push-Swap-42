/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:34:10 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/03 22:37:32 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(float num)
{
	int	dummy;

	dummy = (int)num;
	if ((num - dummy) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}
