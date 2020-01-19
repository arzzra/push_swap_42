/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:17:45 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/19 18:52:48 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_main	*malloc_tmain(void)
{
	t_main	*lst;

	if (!(lst = (t_main*)malloc(sizeof(t_main))))
		return (NULL);
	else
	{
		lst->head_a = NULL;
		lst->head_b = NULL;
		lst->numb_digits = 0;
		lst->mediane = 0;
		lst->cra = 0;
		lst->crb = 0;
		lst->oper = NULL;
		lst->min = 0;
		lst->max = 0;
		lst->len_a = 0;
		lst->len_b = 0;
		lst->inst = NULL;
	}
	return (lst);
}

void	free_all(t_main *ed)
{
	if (ed)
	{
		if (ed->head_a)
		{
			free_stack(ed->head_a);
			ed->head_a = NULL;
		}
		if (ed->head_b)
		{
			ed->head_b = NULL;
			free_stack(ed->head_b);
		}
		if (ed->inst)
		{
			free(ed->inst);
			ed->inst = NULL;
		}
		if (ed->oper)
		{
			free(ed->oper);
			ed->oper = NULL;
		}
		free(ed);
	}
}

void	free_stack(t_stack *head)
{
	t_stack	*lst;

	lst = head;
	while (head)
	{
		lst = head;
		head = head->next;
		free(lst);
	}
}

int		malloc_int(t_main *ed)
{
	int		k;

	k = 0;
	if (ed->numb_digits > 2 &&
	!(ed->inst = (int*)malloc(sizeof(int) * (ed->numb_digits - 2))))
		return (0);
	while (k < ed->numb_digits - 2)
	{
		ed->inst[k] = -1;
		k++;
	}
	return (1);
}

t_stack	*malloc_stack(void)
{
	t_stack		*exp;

	exp = NULL;
	if ((exp = (t_stack*)malloc(sizeof(t_stack))))
	{
		exp->next = NULL;
		exp->prev = NULL;
		exp->seqnumb = 0;
		exp->numb = 0;
	}
	return (exp);
}
