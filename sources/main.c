/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:38:55 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/19 18:53:41 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	output_if_error(t_main *ed)
{
	if (ed)
	{
		free_all(ed);
		write(1, "Error\n", 6);
	}
	exit(1);
}

int		main(int ac, char **av)
{
	char	**numb;
	t_main	*ed_one;

	if (ac == 1)
		output_if_error(NULL);
	if (!(ed_one = malloc_tmain()))
		output_if_error(ed_one);
	if (ac == 2 && (numb = ft_strsplit(av[1], ' ')))
	{
		if (validation_save(ed_one, numb, 0))
			main_algoritm(ed_one);
		else
			output_if_error(ed_one);
	}
	else if (ac > 2)
	{
		if (validation_save(ed_one, av, ac))
			main_algoritm(ed_one);
		else
			output_if_error(ed_one);
	}
	else
		free_all(ed_one);
	return (0);
}
