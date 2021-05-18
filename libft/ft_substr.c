/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:26:32 by hbuisser          #+#    #+#             */
/*   Updated: 2021/05/05 00:34:06 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_str;
	size_t	size_sub;
	char	*sub;

	if (s == NULL)
		return (NULL);
	i = 0;
	size_str = ft_strlen(s);
	if (start > size_str)
		start = size_str;
	if (size_str >= start + len)
		size_sub = len;
	else
		size_sub = size_str - start;
	sub = (char *)malloc (size_sub + 1);
	if (!sub)
		return (NULL);
	while (i < size_sub)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[size_sub] = '\0';
	return (sub);
}
