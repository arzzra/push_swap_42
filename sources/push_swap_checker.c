/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:48:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:08:22 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		operations2(char *oper, t_main *ed)
{
	if (!(ft_strcmp(oper, RRA)))
		reverse_rotate(&(ed->head_a));
	else if (!(ft_strcmp(oper, RRB)))
		reverse_rotate(&(ed->head_b));
	else if (!(ft_strcmp(oper, RRR)))
	{
		reverse_rotate(&(ed->head_a));
		reverse_rotate(&(ed->head_b));
	}
	else
		return (0);
	return (1);
}

int		operations(char *oper, t_main *ed)
{
	if (!(ft_strcmp(oper, SWPA)))
		swap_a_or_b(&(ed->head_a));
	else if (!(ft_strcmp(oper, SWPB)))
		swap_a_or_b(&(ed->head_b));
	else if (!(ft_strcmp(oper, SWPAB)))
	{
		swap_a_or_b(&(ed->head_a));
		swap_a_or_b(&(ed->head_a));
	}
	else if (!(ft_strcmp(oper, PA)))
		push_a_b(&(ed->head_b), &(ed->head_a));
	else if (!(ft_strcmp(oper, PB)))
		push_a_b(&(ed->head_a), &(ed->head_b));
	else if (!(ft_strcmp(oper, RA)))
		rotate(&(ed->head_a));
	else if (!(ft_strcmp(oper, RB)))
		rotate(&(ed->head_b));
	else if (!(ft_strcmp(oper, RR)))
	{
		rotate(&(ed->head_a));
		rotate(&(ed->head_b));
	}
	else
		return (operations2(oper, ed));
	return (1);
}

int		read_stdout(t_main *ed)
{
	char *oper;

	while (get_next_line(0, &oper))
	{
		if (!(operations(oper, ed)))
		{
			free(oper);
			return (0);
		}
		else
			ed->mediane++;
		free(oper);
	}
	return (1);
}
