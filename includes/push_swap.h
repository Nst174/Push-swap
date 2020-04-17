/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:23:46 by taegon-i          #+#    #+#             */
/*   Updated: 2020/03/03 16:00:42 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <../libft/libft.h>
# include <stdio.h>

typedef struct			s_stack
{
	int					value;
	struct s_stack		*previous;
	struct s_stack		*next;
	struct s_stack		*last;
	int					number;

}						t_stack;

typedef struct			s_stack_all
{
	t_stack				*a_stack;
	t_stack				*b_stack;
	size_t				a_size;
	size_t				b_size;
	t_stack				a_hold_first;
	t_stack				a_hold_second;
	t_stack				b_hold_first;
	t_stack				b_hold_second;
	int					min;
	int					max;
	int 				chank_size;
	int					chank_count;
	int 				chank_curr;
	int 				chank_diap;
	int					sred;
	int					check;
}						t_stack_all;

/*
**	push_swap.c
*/

int		main(int argc, char *argv[]);

/*
**	error_messages.c
*/

void		error_message(int n);

/*
**	check_and_parse.c
*/

void 		add_in_stack(t_stack_all *stack, t_stack *elem);
void	parse_array(t_stack_all *stack, int argc, char **argv);
t_stack		*create_elem(int number);
void	parse_string(t_stack_all *stack, char *str);
t_stack_all	*contain_in_a(int argc, char *argv[]);

/*
**	sa_sb_ss.c
*/

void	sa(t_stack_all *stack);
void	sb(t_stack_all *stack);
void	ss(t_stack_all *stack);

/*
**	pa_pb.c
*/

void	pa(t_stack_all *stack_all);
void	pb(t_stack_all *stack_all);
void		add_in_a_stack(t_stack_all *stack, t_stack *elem);
void		add_in_b_stack(t_stack_all *stack, t_stack *elem);

/*
**	ra_rb_rr.c
*/

void	ra(t_stack_all *stack);
void	rb(t_stack_all *stack);
void	rr(t_stack_all *stack);

/*
**	rra_rrb_rrr.c
*/

void	rrb(t_stack_all *stack);
void	rra(t_stack_all *stack);
void	rrr(t_stack_all *stack);

/*
**	utils.c
*/

void	rrx(t_stack_all *stack_all, t_stack *stack);
void	min_and_max(t_stack_all *stack_all);
void	calc_diap_chank(t_stack_all *stack_all);
int		num_chanks(t_stack_all *stack_all);
void	calc_chank_size(t_stack_all *stack_all);
void	numbering_stack(t_stack *stack);
void	count_sred(t_stack_all *stack);

/*
**	sort.c
*/

size_t	found_small(t_stack *stack);
void	small_to_up_stack(t_stack_all *stack_all, size_t counter);


#endif
