/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:05:57 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/15 19:48:39 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rotate_or_revrotate(t_main *ed, int ind)
{
	int		med;

	med = ed->len_a / 2;
	if (ind < med)
		return (ind + 1);
	else
		return (ind - (ed->len_a - 1));
}

int		search_place_ina(t_main *ed, int value)
{
	t_stack	*a;
	int		k;
	int		flag;
	int		ret;

	ret = -2147483648;
	a = ed->head_a;
	k = 0;
	while (a)
	{
		if (a->numb < value && a->numb > ret)
		{
			flag = k;
			ret = a->numb;
		}
		k++;
		a = a->next;
	}
	return (rotate_or_revrotate(ed, flag));
}

void	aligment_a(t_main *ed)
{
	t_stack	*a;
	int		k;
	int		x;
	int		min_value;

	a = ed->head_a;
	k = 0;
	x = 0;
	min_value = a->numb;
	while (a)
	{
		if (min_value > a->numb)
		{
			min_value = a->numb;
			x = k;
		}
		a = a->next;
		k++;
	}
	if (x <= (ed->numb_digits / 2))
		while_ra(ed, x);
	else
		while_rra(ed, ed->numb_digits - x);
}
