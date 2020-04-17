/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:53:32 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:53:34 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack_all *stack)
{
	t_stack *tmp;

	tmp = stack->b_stack;
	stack->b_stack = stack->b_stack->last;
	stack->b_stack->next = tmp;
	tmp->last = NULL;
	tmp->previous = stack->b_stack;
	stack->b_stack->last = stack->b_stack->previous;
	stack->b_stack->last->next = NULL;
	stack->b_stack->previous = NULL;
//	t_stack *tmp;
//	t_stack *tmp_last;
//
//
//	tmp = NULL;
//	tmp_last = NULL;
//
//	if (stack->b_stack)
//	{
//		if (stack->b_stack->next)
//		{
//			if (stack->b_stack->next->next)
//			{
//				tmp = stack->b_stack;
//				tmp_last = stack->b_stack->last;
//
//				while (tmp->next != stack->b_stack->last)
//					tmp = tmp->next;
//				stack->b_stack->last = tmp;
//
//				stack->b_stack->last->next = NULL;
//
//				tmp_last->next = stack->b_stack;
//				tmp_last->previous = NULL;
//				stack->b_stack = tmp_last;
//			}
//			else
//			{
//				stack->check = 1;
//				sb(stack);
//				stack->check = 0;
//			}
//		}
//		else
//			stack->check = 1;
//	}
//	if (stack->check == 0)
		printf("rrb\n");
}

void	rra(t_stack_all *stack)
{
	t_stack *tmp;

	tmp = stack->a_stack;
	stack->a_stack = stack->a_stack->last;
	stack->a_stack->next = tmp;
	tmp->last = NULL;
	tmp->previous = stack->a_stack;
	stack->a_stack->last = stack->a_stack->previous;
	stack->a_stack->last->next = NULL;
	stack->a_stack->previous = NULL;
//	t_stack *tmp;
//	t_stack *tmp_last;
//
//	tmp = NULL;
//	tmp_last = NULL;
//	// rrx(stack, stack->a_stack);
//	if (stack->a_stack)
//	{
//		if (stack->a_stack->next)
//		{
//			if (stack->a_stack->next->next)
//			{
//				tmp = stack->a_stack;
//				tmp_last = stack->a_stack->last;
//
//				while (tmp->next != stack->a_stack->last)
//					tmp = tmp->next;
//				stack->a_stack->last = tmp;
//
//				stack->a_stack->last->next = NULL;
//
//				tmp_last->next = stack->a_stack;
//				tmp_last->previous = NULL;
//				stack->a_stack = tmp_last;
//			}
//			else
//			{
//				stack->check = 1;
//				sa(stack);
//				stack->check = 0;
//			}
//		}
//		else
//			stack->check = 1;
//	}
//	if (stack->check == 0)
		printf("rra\n");
}

void	rrr(t_stack_all *stack)
{
	stack->check = 1;
	rra(stack);
	rrb(stack);
	stack->check = 0;
	printf("rrr\n");
}
