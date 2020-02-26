/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:24:29 by taegon-i          #+#    #+#             */
/*   Updated: 2020/02/20 15:56:33 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack_all		*stack_all;

	if (argc < 2)
		error_message(1);
	stack_all = contain_in_a(argc, argv);

	// sa(stack_all->a_stack);
	pb(stack_all);
	pb(stack_all);

	ss(stack_all);
	pa(stack_all);
	sa(stack_all->a_stack);
	pa(stack_all);



	while(stack_all->a_stack)
	{
		printf("A value - %d\n", stack_all->a_stack->value);
		stack_all->a_stack = stack_all->a_stack->next;
	}
	printf("\n");
	while(stack_all->b_stack)
	{
		printf("B value - %d\n", stack_all->b_stack->value);
		stack_all->b_stack = stack_all->b_stack->next;
	}
	// printf("A value - %d\n", stack_all->a_stack->value);
	// printf("A next->value - %d\n", stack_all->a_stack->next->value);
	// printf("A next->next->value - %d\n", stack_all->a_stack->next->next->value);
	// printf("A next->next->next->value - %d\n\n", stack_all->a_stack->next->next->next->value);

	// printf("A previous->index - %d\n", stack_all->a_stack->previous->index);
	// printf("A index - %d\n", stack_all->a_stack->index);
	// printf("A next->index - %d\n\n", stack_all->a_stack->next->index);


	// printf("B previous->index - %d\n", stack_all->b_stack->previous->index);
	// printf("B index - %d\n", stack_all->b_stack->index);
	// printf("B next->index - %d\n\n", stack_all->b_stack->next->index);


	printf("a_size - %zu\n", stack_all->a_size);
	printf("b_size - %zu\n", stack_all->b_size);

	// printf("B revious->value - %d\n", stack_all->b_stack->previous->value);
	// printf("B value - %d\n", stack_all->b_stack->value);
	// printf("B next->value - %d\n", stack_all->b_stack->next->value);
	// printf("B next->next->value - %d\n", stack_all->b_stack->next->next->value);
	// printf("B next->next->next->value - %d\n\n", stack_all->b_stack->next->next->next->value);

	return (0);
}
