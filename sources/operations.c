/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:33:33 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/19 15:55:51 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		add_front(t_stack **begin, t_stack *lst)
{
	if (!begin | !lst || *begin == lst)
		return (0);
	else
	{
		lst->next = *begin;
		lst->prev = NULL;
		if (*begin)
			(*begin)->prev = lst;
		*begin = lst;
		return (1);
	}
}

int		swap_a_or_b(t_stack **a)
{
	t_stack	*lst;
	t_stack	*lst2;

	if (!(*a) || !(*a)->next)
		return (0);
	else
	{
		lst = *a;
		lst2 = lst->next;
		lst->next = lst2->next;
		lst2->next->prev = lst;
		lst2->next = lst;
		lst->prev = lst2;
		lst2->prev = NULL;
		*a = lst2;
		return (1);
	}
}

int		push_a_b(t_stack **a, t_stack **b)
{
	t_stack	*lstb;

	if (!b || !a || !*a)
		return (0);
	else
	{
		lstb = *a;
		*a = lstb->next;
		if (*a)
			(*a)->prev = NULL;
		add_front(b, lstb);
		return (1);
	}
}

int		rotate(t_stack **st)
{
	t_stack *lst;
	t_stack *lst2;

	lst = *st;
	if (!lst || !(lst->next))
		return (0);
	else
	{
		lst->next->prev = NULL;
		*st = lst->next;
		lst2 = lst;
		while (lst2->next)
			lst2 = lst2->next;
		lst2->next = lst;
		lst->prev = lst2;
		lst->next = NULL;
		return (1);
	}
}

int		reverse_rotate(t_stack **st)
{
	t_stack *lst;

	lst = *st;
	if (!lst || !lst->next)
		return (0);
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->prev->next = NULL;
		add_front(st, lst);
		return (1);
	}
}
