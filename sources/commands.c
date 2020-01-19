/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:17:23 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/15 21:21:07 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	while_rr(t_main *ed, int x)
{
	while (x > 0)
	{
		rotate(&(ed->head_a));
		rotate(&(ed->head_b));
		write_commands(&(ed->oper), RR);
		x--;
	}
}

void	while_rb(t_main *ed, int x)
{
	while (x > 0)
	{
		rotate(&(ed->head_b));
		write_commands(&(ed->oper), RB);
		x--;
	}
}

void	while_ra(t_main *ed, int x)
{
	while (x > 0)
	{
		rotate(&(ed->head_a));
		write_commands(&(ed->oper), RA);
		x--;
	}
}
