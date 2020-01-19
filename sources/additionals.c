/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:14:29 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/14 17:42:28 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_lenav(char **massiv)
{
	size_t	i;

	i = 0;
	while (massiv[i] != NULL)
		i++;
	return (i);
}

void	add_back(t_stack **begin, t_stack *lst)
{
	t_stack	*exp;

	if (!(*begin) || !lst || *begin == lst)
		return ;
	else
	{
		exp = *begin;
		while (exp->next)
			exp = exp->next;
		exp->next = lst;
		lst->prev = exp;
		lst->next = NULL;
	}
}

void	int_massiv_clear(t_main *ed)
{
	int		k;

	k = 0;
	while (k < ed->numb_digits - 2)
	{
		ed->inst[k] = -1;
		k++;
	}
}
