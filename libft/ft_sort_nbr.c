/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:43:07 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/14 20:37:13 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_sort_nbr(int *arr, int len)
{
	int		i;
	int		j;
	int		tmp;
	int		*ret;

	ret = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		ret[i] = arr[i];
	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (ret[i] > ret[j])
			{
				tmp = ret[i];
				ret[i] = ret[j];
				ret[j] = tmp;
			}
		}
	}
	return (ret);
}
