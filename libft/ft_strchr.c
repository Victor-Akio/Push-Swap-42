/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:55:01 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/23 21:41:32 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	if (!ptr || !*ptr)
		return (0);
	i = -1;
	while (ptr[++i])
	{
		if (ptr[i] == c)
			return (ptr + i);
	}
	return (0);
}
