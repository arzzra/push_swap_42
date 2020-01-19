/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:22:49 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/18 16:15:30 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# define SWPA "sa"
# define SWPB "sb"
# define SWPAB "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct			s_main
{
	struct s_stack		*head_a;
	struct s_stack		*head_b;
	int					numb_digits;
	int					mediane;
	int					*inst;
	int					len_a;
	int					len_b;
	int					max;
	int					min;
	int					cra;
	int					crb;
	char				*oper;
}						t_main;

typedef struct			s_stack
{
	int					numb;
	size_t				seqnumb;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

/*
**		validation.c
*/

int						validation_save(t_main *ed_one, char **av, int ac);
int						duplicate_check(t_main *ed_one);
int						search_duplicate(t_stack *stck);

/*
**		algos.c
*/

void					quick_sort(int *stk, int l, int r);
int						*struct_int(t_main *ed);
int						check_sorting(t_main *ed, int *nums);
int						search_med_sorting_check(t_main *ed_one);

/*
**		main.c
*/

void					output_if_error(t_main *ed);

/*
**		malloc.c
*/

t_main					*malloc_tmain(void);
void					free_all(t_main *ed);
void					free_stack(t_stack *head);
int						malloc_int(t_main *ed);
t_stack					*malloc_stack(void);

/*
**		commands.c & commands2.c
*/

void					while_rr(t_main *ed, int x);
void					while_rb(t_main *ed, int x);
void					while_ra(t_main *ed, int x);
void					while_rrr(t_main *ed, int x);
void					while_rrb(t_main *ed, int x);
void					while_rra(t_main *ed, int x);

/*
**		operations.c
*/

int						add_front(t_stack **begin, t_stack *lst);
int						swap_a_or_b(t_stack **a);
int						push_a_b(t_stack **a, t_stack **b);
int						rotate(t_stack **st);
int						reverse_rotate(t_stack **st);

/*
**		save.c
*/

int						is_str_digit_only(char *str);
t_stack					*savenub(char *av);
t_stack					*save_stack(int ac, char **av, int i);

/*
**		additionals.c
*/

size_t					ft_lenav(char **massiv);
void					add_back(t_stack **begin, t_stack *lst);
void					int_massiv_clear(t_main *ed);

/*
**		sorting.c & sorting2.c & sorting3.c & sorting4.c
*/

void					main_algoritm(t_main *ed);
void					comand_calc(t_main *ed, int f);
int						search_next_step(t_main *ed);
int						least_number_of_steps(t_main *ed);
int						step_count_calc(t_main *ed, int	i, int value);
void					pushin_to_b(t_main *ed);
void					pushin_to_b_1(t_main *ed);
int						len_stack(t_stack *st);
void					write_commands(char **log, char *cmd);
void					push_to_a(t_main *ed);
int						rotate_or_revrotate(t_main *ed, int ind);
int						search_place_ina(t_main *ed, int value);
void					aligment_a(t_main *ed);

/*
**		for_5_digits.c
*/

void					for_five_dig(t_main *ed);
void					sort_a(t_main *ed);

/*
**		checker.c
*/

int						read_stdout(t_main *ed);

#endif
