/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:58:05 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/26 20:06:22 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	div_10(int x, int len)
{
	while (x)
	{
		x = x / 10;
		len++;
	}
	return (len);
}

static char	*ft_neg(int n)
{
	int		tmpn;
	int		len;
	char	*str;

	n *= -1;
	tmpn = n;
	len = 3;
	len = div_10(tmpn, len);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_zero(void)
{
	int		len;
	char	*str;

	len = 2;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_zero());
	if (n <= 0)
		return (ft_neg(n));
	tmpn = n;
	len = 2;
	len = div_10(tmpn, len);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
