/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:54:34 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/19 18:55:52 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sorted(t_main *ed)
{
	t_stack	*lst;
	int		numb;

	lst = ed->head_a;
	if (lst && !ed->head_b)
	{
		while (lst->next)
		{
			numb = lst->numb;
			lst = lst->next;
			if (numb > lst->numb)
				return (0);
			numb = lst->numb;
		}
	}
	else
		return (0);
	return (1);
}

void	output_error(t_main *ed, int numb_err)
{
	char	*count_step;

	if (numb_err == 1)
	{
		free_all(ed);
		write(1, "Error\n", 6);
	}
	else if (numb_err == 2)
	{
		write(1, "KO\n", 3);
	}
	else
	{
		write(1, "OK\n", 3);
		count_step = ft_itoa(ed->mediane);
		write(1, "Total steps:", 12);
		write(1, count_step, ft_strlen(count_step));
		write(1, "\n", 1);
		free(count_step);
	}
	exit(1);
}

void	main_two(t_main *ed)
{
	if (read_stdout(ed))
	{
		if (sorted(ed))
			output_error(ed, 3);
		else
			output_error(ed, 2);
		free_all(ed);
	}
	else
	{
		output_error(ed, 1);
		free_all(ed);
	}
}

int		main(int ac, char **av)
{
	char	**numb;
	t_main	*ed_one;

	if (ac == 1)
		exit(1);
	if (!(ed_one = malloc_tmain()))
		output_error(NULL, 1);
	if (ac == 2 && (numb = ft_strsplit(av[1], ' ')))
	{
		if (validation_save(ed_one, numb, 0))
			main_two(ed_one);
		else
			output_error(ed_one, 1);
	}
	else if (ac > 2)
	{
		if (validation_save(ed_one, av, ac))
			main_two(ed_one);
		else
			output_error(ed_one, 1);
	}
	else
		free_all(ed_one);
	return (0);
}
