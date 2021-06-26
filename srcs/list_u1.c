/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_u1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:36:43 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/25 01:46:04 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The file has some list associated functions with generic purpose.
*/

/*
** It is responsible fro freeing the stack when needed
*/
void	free_stk(t_stk **stk)
{
	t_stk	*tmp;

	if (*stk)
	{
		while (*stk)
		{
			tmp = (*stk)->nxt;
			free(*stk);
			*stk = NULL;
			(*stk) = tmp;
		}
		free(*stk);
		*stk = NULL;
	}
}

/*
** It find the size of the list received in 'stk a'
*/
int	list_size(t_stk *a)
{
	int		len;

	len = 0;
	while (a)
	{
		len++;
		a = a->nxt;
	}
	return (len);
}

/*
** It will add a 'new' item in the end of the stack
*/
void	add_back(t_stk **top, t_stk *new)
{
	t_stk	*tmp;

	if (*top == NULL)
		*top = new;
	else
	{
		tmp = *top;
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = new;
		new->prv = tmp;
	}
}

/*
**
*/
void	add_back_r(t_stk **top)
{
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = NULL;
	tmp1 = *top;
	tmp2 = (*top)->prv;
	while (tmp1->nxt)
		tmp1 = tmp1->nxt;
	tmp1->nxt = tmp2;
	tmp1->nxt->prv = tmp1;
	tmp1->nxt->nxt = NULL;
}

/*
** This will ad a 'new' number in the front of the stack
*/
void	add_front(t_stk **top, t_stk *new)
{
	new->nxt = (*top);
	new->prv = NULL;
	if ((*top) != NULL)
		(*top)->prv = new;
	(*top) = new;
}
