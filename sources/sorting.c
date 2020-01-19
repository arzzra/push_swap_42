/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:55:01 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:09:43 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		step_count_calc(t_main *ed, int i, int value)
{
	int		count;
	int		cra;

	if (i <= (ed->len_b / 2))
	{
		cra = search_place_ina(ed, value);
		if (cra >= 0)
			return (cra >= i ? cra : i);
		else
			return (cra * (-1) + i);
	}
	else
	{
		count = (i - ed->len_b) * (-1);
		cra = search_place_ina(ed, value);
		if (cra <= 0)
			return (cra * (-1) >= count ? cra * (-1) : count);
		else
			return (count + cra);
	}
}

int		least_number_of_steps(t_main *ed)
{
	int		k;
	int		step;
	int		flag;

	k = 0;
	step = 2147483647;
	if (ed->len_b == 0)
		return (-1);
	while (k < ed->len_b && ed->inst[k] != -1)
	{
		if (ed->inst[k] < step)
		{
			step = ed->inst[k];
			flag = k;
		}
		k++;
	}
	return (flag);
}

int		search_next_step(t_main *ed)
{
	int		k;
	t_stack *b;
	int		der;

	k = 0;
	ed->len_b = len_stack(ed->head_b);
	ed->len_a = len_stack(ed->head_a);
	b = ed->head_b;
	while (k < ed->len_b && b)
	{
		der = step_count_calc(ed, k, b->numb);
		ed->inst[k] = der;
		k++;
		b = b->next;
	}
	return (least_number_of_steps(ed));
}

void	comand_calc(t_main *ed, int f)
{
	t_stack	*b;
	int		k;

	b = ed->head_b;
	k = 0;
	ed->crb = (ed->len_b / 2) >= f ? f : f - ed->len_b;
	while (b && k != f)
	{
		k++;
		b = b->next;
	}
	ed->cra = search_place_ina(ed, b->numb);
}

void	main_algoritm(t_main *ed)
{
	int		f;

	if (search_med_sorting_check(ed))
	{
		if (ed->numb_digits == 5)
			for_five_dig(ed);
		else if (ed->numb_digits == 3)
			sort_a(ed);
		else
		{
			pushin_to_b(ed);
			while ((f = search_next_step(ed)) != -1)
			{
				comand_calc(ed, f);
				push_to_a(ed);
				int_massiv_clear(ed);
			}
			aligment_a(ed);
		}
		write(1, ed->oper, ft_strlen(ed->oper));
	}
	free_all(ed);
}
