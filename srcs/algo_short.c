/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:04:45 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 00:20:59 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The normalize function is responsible for the smart rotation.
** We are currently using the lower value as index compare
** with the position found (num); num will find the better
** where the lower number is located and rotate accordingly;
*/
void	normalize(t_stk **a, t_stk **b, t_var *v, int min)
{
	int	idx;
	int	num;

	idx = get_idx((*a), min, 1);
	num = (list_size((*a)) / 2);
	if (num > idx)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

/*
** The sort method will use the lower value as parameter
** If the second number is the lower value, it will rotate
** the first and second element.
** If the first element is the lower number it will be sent
** to stack 'b';
**
** In the other hand, while the lower number don't reach the
** it will use a smart rotation to met this condition;
** Once met, i will send the top number to the stack 'b'
**
** This will occur until there is '3' numbers to be arranged;
*/
void	case_with_10(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		min;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->nxt;
		if ((*a)->num != min && tmp1 && tmp1->num == min)
			pick_case(a, b, SA, v);
		while (min != (*a)->num)
			normalize(a, b, v, min);
		if (min == (*a)->num)
		{
			tmp2 = *a;
			pick_case(a, b, PB, v);
			free(tmp2);
			i--;
		}
	}
}

/*
** This will execute both operations, being the first 'sa'.
*/
void	sort_3(t_stk **a, t_stk **b, t_var *v, int op)
{
	pick_case(a, b, SA, v);
	pick_case(a, b, op, v);
}

/*
** This parser first find the lowest value within the list;
**
** FIRST CASE - if the first number is lower than the second one and
** the third number is the minimun value, it just send the last number
** to the top;
**
** SECOND CASE - if first number is greater than the second and the
** third one is the minimun value, it swap the first and second and
** than send the third to the top.
**
** THIRD CASE - The minimun value is the second number, than it will
** will find if the first number is greater than the third one,
** and swap accordingly.
**
** FOURTH CASE - the last case occur if the first number is the
** minimun value and the second is lower than the third one.
*/
void	case_with_3(t_stk **a, t_stk **b, int len, t_var *v)
{
	t_stk	*tmp;
	int		min;

	tmp = ft_lst_bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->num < (*a)->nxt->num && tmp->num == min)
			pick_case(a, b, RRA, v);
		else if ((*a)->num > (*a)->nxt->num && tmp->num == min)
			sort_3(a, b, v, RRA);
		else if ((*a)->nxt->num == min)
		{
			if ((*a)->num < tmp->num)
				pick_case(a, b, SA, v);
			else if ((*a)->num > tmp->num)
				pick_case(a, b, RA, v);
		}
		else if ((*a)->num == min && (*a)->nxt->num > tmp->num)
			sort_3(a, b, v, RA);
	}
}

/*
** This parser will find if the stack meet its conditions
** and execute the correct operation if needed.
**
** If len = 2 and the first number is bigger than the last one,
** it will call the operator 'sa' and swap the numbers;
** as for a len = 3, it will enter the case_with_3 sort function;
** for any lenght within 3 > len >= 1 it will use an tricky logic,
** sending the 1-7 greater numbers to stack b, depending of the length
** of the list (if there is 10 numbers, it will send 7 numbers).
** After that, it will sort the 3 remaining numbers in stack a and 
** after that returning in order all numbers in stack 'b' to stack 'a'.
**
** Freeing every memory allocated to stack 'a' and 'b'.
*/
void	sort_short(t_stk **a, t_stk **b, int len, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->num > (*a)->nxt->num)
		pick_case(a, b, SA, v);
	if (len <= 3)
		case_with_3(a, b, len, v);
	else if (len > 3)
	{
		case_with_10(a, b, len, v);
		case_with_3(a, b, 3, v);
		while ((*b))
		{
			tmp = *b;
			pick_case(a, b, PA, v);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}
