/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:38:07 by vminomiy          #+#    #+#             */
/*   Updated: 2021/04/25 22:36:12 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_all_spaces(char *str)
{
	int			i;
	int			j;

	i = -1;
	j = ft_strlen(str);
	while ((++i < j) && (ft_isspace_nl(str[i]) && str[i] != '\n'))
		;
	if (i == j)
		return (1);
	else
		return (0);
}
