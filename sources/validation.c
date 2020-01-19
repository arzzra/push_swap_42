/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:12:12 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:10:39 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_massiv(char **mass)
{
	int		k;

	k = 0;
	while (mass[k])
	{
		free(mass[k]);
		k++;
	}
	free(mass);
}

int			search_duplicate(t_stack *stck)
{
	int		x;

	x = stck->numb;
	stck = stck->next;
	while (stck)
	{
		if (x == stck->numb)
			return (1);
		stck = stck->next;
	}
	return (0);
}

int			duplicate_check(t_main *ed_one)
{
	t_stack	*trt;

	trt = ed_one->head_a;
	while (trt)
	{
		if (search_duplicate(trt))
			return (0);
		trt = trt->next;
	}
	return (1);
}

int			validation_save(t_main *ed_one, char **av, int ac)
{
	if (!ac)
	{
		ac = ft_lenav(av);
		ed_one->numb_digits = ac;
		if (!(ed_one->head_a = save_stack(ac, av, 0)))
		{
			free_massiv(av);
			return (0);
		}
		free_massiv(av);
	}
	else
	{
		ed_one->numb_digits = ac - 1;
		if (!(ed_one->head_a = save_stack(ac, av, 1)))
			return (0);
	}
	if (!(duplicate_check(ed_one)) || !(malloc_int(ed_one)))
		return (0);
	else
		return (1);
}
