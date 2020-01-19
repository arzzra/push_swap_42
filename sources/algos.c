/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:22 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:05:59 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *stk, int l, int r)
{
	int		tmp;

	tmp = stk[l];
	stk[l] = stk[r];
	stk[r] = tmp;
}

void		quick_sort(int *stk, int l, int r)
{
	int		low;
	int		high;
	int		med;

	low = r;
	high = l;
	med = stk[(low + high) / 2];
	while (high <= low)
	{
		while (stk[high] < med)
			high++;
		while (stk[low] > med)
			low--;
		if (high <= low)
			ft_swap(stk, high++, low--);
	}
	if (l < low)
		quick_sort(stk, l, low);
	if (r > high)
		quick_sort(stk, high, r);
}

int			*struct_int(t_main *ed)
{
	int		*dig;
	int		i;
	t_stack	*lst;

	if (!(dig = (int*)malloc(sizeof(int) * ed->numb_digits)))
		return (NULL);
	i = 0;
	lst = ed->head_a;
	while (i < ed->numb_digits && lst)
	{
		dig[i] = lst->numb;
		i++;
		lst = lst->next;
	}
	return (dig);
}

int			check_sorting(t_main *ed, int *nums)
{
	int		i;
	t_stack	*lst;

	i = 0;
	lst = ed->head_a;
	while (i < ed->numb_digits && lst)
	{
		if (nums[i] != lst->numb)
			return (1);
		i++;
		lst = lst->next;
	}
	return (0);
}

int			search_med_sorting_check(t_main *ed_one)
{
	int		*dig;
	int		med_id;

	if (!(dig = struct_int(ed_one)))
		return (0);
	quick_sort(dig, 0, ed_one->numb_digits - 1);
	med_id = ed_one->numb_digits / 2;
	ed_one->mediane = dig[med_id];
	ed_one->max = dig[ed_one->numb_digits - 1];
	ed_one->min = dig[0];
	if (!(check_sorting(ed_one, dig)) || ed_one->numb_digits == 1)
	{
		free(dig);
		return (0);
	}
	free(dig);
	return (1);
}
