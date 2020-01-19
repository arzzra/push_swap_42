/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:18:03 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/15 21:21:48 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	while_rrr(t_main *ed, int x)
{
	while (x > 0)
	{
		reverse_rotate(&(ed->head_a));
		reverse_rotate(&(ed->head_b));
		write_commands(&(ed->oper), RRR);
		x--;
	}
}

void	while_rrb(t_main *ed, int x)
{
	while (x > 0)
	{
		reverse_rotate(&(ed->head_b));
		write_commands(&(ed->oper), RRB);
		x--;
	}
}

void	while_rra(t_main *ed, int x)
{
	while (x > 0)
	{
		reverse_rotate(&(ed->head_a));
		write_commands(&(ed->oper), RRA);
		x--;
	}
}
