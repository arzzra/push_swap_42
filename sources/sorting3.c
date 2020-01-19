/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:47:25 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:09:18 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_a_3(t_main *ed)
{
	if (ed->cra == 0)
	{
		if (ed->crb >= 0)
			while_rb(ed, ed->crb);
		else
			while_rrb(ed, ed->crb * (-1));
	}
	else if (ed->crb == 0)
	{
		if (ed->cra >= 0)
			while_ra(ed, ed->cra);
		else
			while_rra(ed, ed->cra * (-1));
	}
	else
	{
		if (ed->cra > 0)
			while_ra(ed, ed->cra);
		else
			while_rra(ed, ed->cra * (-1));
		if (ed->crb > 0)
			while_rb(ed, ed->crb);
		else
			while_rrb(ed, ed->crb * (-1));
	}
}

static void	push_to_a_2(t_main *ed)
{
	int		together;

	together = ed->crb >= ed->cra ? ed->crb * (-1) : ed->cra * (-1);
	while_rrr(ed, together);
	if (ed->crb > ed->cra)
		while_rra(ed, ed->cra * (-1) - together);
	else
		while_rrb(ed, ed->crb * (-1) - together);
}

static void	push_to_a_1(t_main *ed)
{
	int		together;

	together = ed->crb >= ed->cra ? ed->cra : ed->crb;
	while_rr(ed, together);
	if (ed->crb > ed->cra)
		while_rb(ed, ed->crb - together);
	else
		while_ra(ed, ed->cra - together);
}

void		push_to_a(t_main *ed)
{
	if (ed->crb > 0 && ed->cra > 0)
		push_to_a_1(ed);
	else if (ed->crb < 0 && ed->cra < 0)
		push_to_a_2(ed);
	else
		push_to_a_3(ed);
	push_a_b((&ed->head_b), &(ed->head_a));
	write_commands(&(ed->oper), PA);
}
