/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:22:01 by hbuisser          #+#    #+#             */
/*   Updated: 2021/05/05 01:55:29 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			t;

	t = count * size;
	ptr = (unsigned char *)malloc(t);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < t)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
