/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:52:51 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:52:53 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void		add_in_a_stack_2(t_stack_all *stack, t_stack *elem)
{
	t_stack	*tmp;

	if (stack && elem)
	{
		if (!stack->a_stack)
		{
			stack->a_stack = elem;
			stack->a_stack->previous = NULL;
			stack->a_stack->next = NULL;
			stack->a_stack->last = elem;

		}
		else
		{
			tmp = stack->a_stack;
			stack->a_stack = elem;
			stack->a_stack->next = tmp;
			stack->a_stack->next->previous = elem;
			while(tmp->next)
				tmp = tmp->next;
			stack->a_stack->last = tmp;
		}
		stack->a_size++;
	}
}

void		add_in_b_stack(t_stack_all *stack, t_stack *elem)
{
	t_stack	*tmp;

	if (stack && elem)
	{
		if (!stack->b_stack)
		{
			stack->b_stack = elem;
			stack->b_stack->previous = NULL;
			stack->b_stack->next = NULL;
			stack->b_stack->last = elem;

		}
		else
		{
			tmp = stack->b_stack;
			stack->b_stack = elem;
			stack->b_stack->next = tmp;
			stack->b_stack->next->previous = elem;
			while(tmp->next)
				tmp = tmp->next;
			stack->b_stack->last = tmp;
		}
		stack->b_size++;
	}
}

void		add_in_a_stack(t_stack_all *stack, t_stack *elem)
{
	t_stack	*tmp;

	if (stack && elem)
	{
		if (!stack->a_stack)
		{
			stack->a_stack = elem;
			stack->a_stack->previous = NULL;
			stack->a_stack->next = NULL;
			stack->a_stack->last = elem;
		}
		else
		{
			tmp = stack->a_stack;
			stack->a_stack = elem;
			stack->a_stack->next = tmp;
			stack->a_stack->previous = elem;
			while(tmp->next)
				tmp = tmp->next;
			stack->a_stack->last = tmp;
		}
		stack->a_size++;
	}
}

void	pa(t_stack_all *stack_all)
{
	t_stack *tmp;

	if (stack_all->b_stack)
	{
		add_in_a_stack_2(stack_all, create_elem(stack_all->b_stack->value));
		if (!stack_all->b_stack->next)
			stack_all->b_stack = NULL;
		else
		{
			stack_all->b_stack = stack_all->b_stack->next;
			tmp = stack_all->a_stack;
			while(tmp->next)
				tmp = tmp->next;
			stack_all->a_stack->last = tmp;
			stack_all->b_stack->previous = NULL;
		}
		stack_all->b_size--;
		printf("pa\n");
	}
}

void	pb(t_stack_all *stack_all)
{
	t_stack *tmp;

	if (stack_all->a_stack)
	{
		add_in_b_stack(stack_all, create_elem(stack_all->a_stack->value));

		if (!stack_all->a_stack->next)
			stack_all->a_stack = NULL;
		else
		{
			stack_all->a_stack = stack_all->a_stack->next;
			tmp = stack_all->a_stack;
			while(tmp->next)
				tmp = tmp->next;
			stack_all->a_stack->last = tmp;
			stack_all->a_stack->previous = NULL;
		}
		// while(stack_all->a_stack)
		// {
		// 	printf("A value - %d\n", stack_all->a_stack->value);
		// 	stack_all->a_stack = stack_all->a_stack->next;
		// }
		stack_all->a_size--;

		printf("pb\n");
	}
}
