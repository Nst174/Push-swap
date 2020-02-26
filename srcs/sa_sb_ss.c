/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:12:05 by taegon-i          #+#    #+#             */
/*   Updated: 2020/02/20 15:54:29 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	int tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	printf("sb\n");
}

void	ss(t_stack_all *stack)
{
	sa(stack->a_stack);
	sb(stack->b_stack);
	printf("ss\n");
}
