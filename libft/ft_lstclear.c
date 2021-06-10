/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:57:43 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/26 22:30:45 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (*lst == NULL || del == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		*lst = ptr;
		ft_lstdelone(*lst, del);
		ptr = ptr->next;
	}
	*lst = NULL;
}
