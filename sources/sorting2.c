/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:32:07 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 15:43:08 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_commands(char **log, char *cmd)
{
	char	*for_free;

	if (!(*log))
	{
		*log = ft_strdup(cmd);
		for_free = *log;
		*log = ft_strjoin(*log, "\n");
		free(for_free);
	}
	else
	{
		for_free = *log;
		*log = ft_strjoin(*log, cmd);
		free(for_free);
		for_free = *log;
		*log = ft_strjoin(*log, "\n");
		free(for_free);
	}
}

int		len_stack(t_stack *st)
{
	int		k;

	k = 0;
	while (st)
	{
		k++;
		st = st->next;
	}
	return (k);
}

void	pushin_to_b_1(t_main *ed)
{
	push_a_b(&(ed->head_a), &(ed->head_b));
	write_commands(&(ed->oper), PB);
	if (ed->head_b && ed->head_b->numb >= ed->mediane)
	{
		if (rotate(&(ed->head_b)))
			write_commands(&(ed->oper), RB);
	}
}

void	pushin_to_b(t_main *ed)
{
	t_stack	*a;

	a = ed->head_a;
	while (a && len_stack(ed->head_a) > 2)
	{
		a = ed->head_a;
		if (a->numb != ed->min && a->numb != ed->max)
			pushin_to_b_1(ed);
		else
		{
			rotate(&(ed->head_a));
			if (ed->oper == NULL)
				write_commands(&(ed->oper), RA);
			else
				write_commands(&(ed->oper), RA);
		}
	}
	if (ed->head_a->numb != ed->max)
	{
		rotate(&(ed->head_a));
		write_commands(&(ed->oper), RA);
	}
}
