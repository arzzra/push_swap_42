/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_5_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:45:52 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:06:26 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_min(t_main *ed)
{
	t_stack	*lst;
	int		k;

	k = 0;
	lst = ed->head_a;
	while (lst && lst->numb != ed->min)
	{
		lst = lst->next;
		k++;
	}
	if (k > 3)
		while_rra(ed, 5 - k);
	else
		while_ra(ed, k);
	push_a_b(&(ed->head_a), &(ed->head_b));
	write_commands(&(ed->oper), PB);
}

void	push_max(t_main *ed)
{
	t_stack	*lst;
	int		k;

	k = 0;
	lst = ed->head_a;
	while (lst && lst->numb != ed->max)
	{
		lst = lst->next;
		k++;
	}
	if (k == 3)
		while_rra(ed, 4 - k);
	else
		while_ra(ed, k);
	push_a_b(&(ed->head_a), &(ed->head_b));
	write_commands(&(ed->oper), PB);
}

void	swap_stack(t_main *ed, int x)
{
	swap_a_or_b(&(ed->head_a));
	write_commands(&(ed->oper), SWPA);
	if (x < 0)
		while_rra(ed, x * (-1));
	else if (x > 0)
		while_ra(ed, x);
}

void	sort_a(t_main *ed)
{
	if (ed->head_a->numb == ed->mediane)
	{
		if (ed->head_a->next->numb < ed->head_a->numb)
			swap_stack(ed, 0);
		else
			while_rra(ed, 1);
	}
	else if (ed->head_a->numb > ed->mediane)
	{
		if (ed->head_a->next->numb < ed->head_a->next->next->numb)
			while_ra(ed, 1);
		else
			swap_stack(ed, -1);
	}
	else if (ed->head_a->numb < ed->mediane &&
	ed->head_a->next->numb > ed->mediane)
		swap_stack(ed, 1);
}

void	for_five_dig(t_main *ed)
{
	push_min(ed);
	push_max(ed);
	sort_a(ed);
	push_a_b(&(ed->head_b), &(ed->head_a));
	write_commands(&(ed->oper), PA);
	while_ra(ed, 1);
	push_a_b(&(ed->head_b), &(ed->head_a));
	write_commands(&(ed->oper), PA);
}
