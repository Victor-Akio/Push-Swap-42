/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:56:57 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/27 16:56:58 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	p;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	p = (unsigned char)c;
	i = 0;
	while (i < n && (i == 0 || ((i > 0) && s[i - 1] != p)))
	{
		d[i] = s[i];
		i++;
	}
	if (i > 0 && s[i - 1] == p)
		return (d + i);
	else
		return (NULL);
}
