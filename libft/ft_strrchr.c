/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:53:00 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/27 16:53:04 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	ptr = (char *)s + len - 1;
	if (c == '\0')
		return (ptr + 1);
	while (len > 0)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
		len--;
	}
	if (c == '\0')
	{
		ptr++;
		return (ptr);
	}
	return (NULL);
}
