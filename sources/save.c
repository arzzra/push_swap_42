/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:16:00 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/19 18:17:49 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_str_digit_only(char *str)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (str[i] && str[i] == ' ' && str[i] == '\n')
		i++;
	if ((str[i] == '+' || str[i] == '-') &&
	str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		i++;
		x++;
	}
	while (str[i] && str[i] == ' ' && str[i] == '\n')
		i++;
	if (i == ft_strlen(str) && x <= 10)
		return (1);
	else
		return (0);
}

static int64_t	ft_atoi2(const char *str)
{
	long	q;
	int		e;

	q = 0;
	e = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	*str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		e *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		q = q * 10 + (*str - '0');
		if (q < 0 && e == -1)
			return (0);
		else if (q < 0 && e == 1)
			return (-1);
		str++;
	}
	return (q * e);
}

t_stack			*savenub(char *av)
{
	t_stack	*lst;
	long	buf;

	lst = NULL;
	if (av)
	{
		if (is_str_digit_only(av) && (lst = malloc_stack()))
		{
			buf = ft_atoi2(av);
			if (buf <= 2147483647 && buf >= -2147483648)
				lst->numb = buf;
			else
			{
				free(lst);
				return (NULL);
			}
		}
	}
	return (lst);
}

t_stack			*save_stack(int ac, char **av, int i)
{
	t_stack	*head_a;
	t_stack	*lst;

	head_a = NULL;
	while (i < ac)
	{
		if (!head_a && (lst = savenub(av[i])))
			head_a = lst;
		else if ((lst = savenub(av[i])))
			add_back(&head_a, lst);
		else
		{
			free_stack(head_a);
			return (NULL);
		}
		i++;
	}
	return (head_a);
}
