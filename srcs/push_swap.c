/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:53:10 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:53:12 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int checker(t_stack_all *stack)
{
	t_stack *temp;

	temp = stack->a_stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
	}
	return (1);
}



int		main(int argc, char *argv[])
{
	t_stack_all		*stack_all;

	if (argc < 2)
		error_message(1);
	stack_all = contain_in_a(argc, argv);

	count_sred(stack_all);
	min_and_max(stack_all);
	calc_diap_chank(stack_all);
	calc_chank_size(stack_all);
	numbering_stack(stack_all->a_stack);
//	sa(stack_all);
//	pb(stack_all);
//	pb(stack_all);
//	pb(stack_all);
//	sa(stack_all);
//	pa(stack_all);
//	pa(stack_all);
//	pa(stack_all);

	while(stack_all->a_stack)
	{
		printf("A value - %d\n", stack_all->a_stack->value);
		printf("number - %d\n", stack_all->a_stack->number);
		stack_all->a_stack = stack_all->a_stack->next;
	}
	printf("\n");
	// while(stack_all->b_stack)
	// {
	// 	printf("B value - %d\n", stack_all->b_stack->value);
	// 	stack_all->b_stack = stack_all->b_stack->next;
	// }

	while(stack_all->b_stack)
	{
		printf("B value - %d\n", stack_all->b_stack->value);
		stack_all->b_stack = stack_all->b_stack->next;
	}
	printf("a_size - %zu\n", stack_all->a_size);
	printf("b_size - %zu\n", stack_all->b_size);
	printf("sred - %zu\n", stack_all->sred);
	printf("min - %zu\n", stack_all->min);
	printf("max - %zu\n", stack_all->max);
	printf("diap_chank - %zu\n", stack_all->chank_diap);
	printf("chank_size - %zu\n", stack_all->chank_size);

	// printf("a_last - %d\n", stack_all->a_stack->last->value);
	return (0);
}
