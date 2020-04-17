/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:53:41 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:53:42 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_all *stack)
{
	int tmp;

	if (stack->a_stack->next)
	{
		tmp = stack->a_stack->value;
		stack->a_stack->value = stack->a_stack->next->value;
		stack->a_stack->next->value = tmp;
		if (stack->check == 0)
			printf("sa\n");
	}
}

void	sb(t_stack_all *stack)
{
	int tmp;

	if (stack->b_stack->next)
	{
		tmp = stack->b_stack->value;
		stack->b_stack->value = stack->b_stack->next->value;
		stack->b_stack->next->value = tmp;
		if (stack->check == 0)
			printf("sb\n");
	}
}

void	ss(t_stack_all *stack)
{
	stack->check = 1;
	sa(stack);
	sb(stack);
	stack->check = 0;
	printf("ss\n");
}
