/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:24:23 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:53:23 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_in_stack_end(t_stack *stack, t_stack *elem)
{
	t_stack	*tmp;

	if (stack && elem)
	{
		if (!stack)
		{
			stack = elem;
			stack->previous = NULL;
			stack->next = NULL;
		}
		else
		{
			tmp = stack;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = elem;
			elem->previous = tmp;
		}
		stack->last = elem;
	}
}

void	ra(t_stack_all *stack)
{
	int tmp;

	if (stack->a_stack)
	{
		if (stack->a_stack->next)
		{
			if (stack->a_stack->next->next)
			{
				// temp1 = stack->a_stack;
				// tmp = stack->a_stack->value;
				//
				// while (stack->a_stack->next)
				// {
				// 	stack->a_stack->value = stack->a_stack->next->value;
				// 	stack->a_stack = stack->a_stack->next;
				// }
				// stack->a_stack->value = tmp;
				// stack->a_stack = temp1;

				tmp = stack->a_stack->value;
				stack->a_stack = stack->a_stack->next;
				add_in_stack_end(stack->a_stack, create_elem(tmp));
				stack->a_stack->previous = NULL;
			}
			else
			{
				stack->check = 1;
				sa(stack);
				stack->check = 0;
			}
		}
	}
	if (stack->check == 0)
		printf("ra\n");
}

void	rb(t_stack_all *stack)
{
	int tmp;

	if (stack->b_stack)
	{
		if (stack->b_stack->next)
		{
			if (stack->b_stack->next->next)
			{
				// temp1 = stack->a_stack;
				// tmp = stack->a_stack->value;
				//
				// while (stack->a_stack->next)
				// {
				// 	stack->a_stack->value = stack->a_stack->next->value;
				// 	stack->a_stack = stack->a_stack->next;
				// }
				// stack->a_stack->value = tmp;
				// stack->a_stack = temp1;

				tmp = stack->b_stack->value;
				stack->b_stack = stack->b_stack->next;
				add_in_stack_end(stack->b_stack, create_elem(tmp));
				stack->b_stack->previous = NULL;
			}
			else
			{
				stack->check = 1;
				sb(stack);
				stack->check = 0;
			}
		}
	}
	if (stack->check == 0)
		printf("rb\n");
}

void	rr(t_stack_all *stack)
{
	stack->check = 1;
	ra(stack);
	rb(stack);
	stack->check = 0;
	printf("rr\n");
}
