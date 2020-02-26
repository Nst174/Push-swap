/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:54:42 by taegon-i          #+#    #+#             */
/*   Updated: 2020/02/20 15:52:58 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		}
		else
		{
			tmp = stack->b_stack;
			stack->b_stack = elem;
			stack->b_stack->next = tmp;
			stack->b_stack->previous = elem;

			// tmp = stack->b_stack;
			// while (tmp->next)
			// {
			// 	tmp = tmp->next;
			// }
			// tmp->next = elem;
			// elem->previous = tmp;
		}
		stack->b_size++;
		stack->b_stack->index = stack->b_size;
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
		}
		else
		{
			tmp = stack->a_stack;
			stack->a_stack = elem;
			stack->a_stack->next = tmp;
			stack->a_stack->previous = elem;

			// tmp = stack->b_stack;
			// while (tmp->next)
			// {
			// 	tmp = tmp->next;
			// }
			// tmp->next = elem;
			// elem->previous = tmp;
		}
		stack->a_size++;
		stack->a_stack->index = stack->a_size;
	}
}

void	pa(t_stack_all *stack_all)
{
	if (stack_all->b_stack)
	{
		add_in_a_stack(stack_all, create_elem(stack_all->b_stack->value));
		if (!stack_all->b_stack->next)
			stack_all->b_stack = NULL;
		else
		{
			stack_all->b_stack = stack_all->b_stack->next;
			stack_all->b_stack->previous = NULL;
		}
		stack_all->b_size--;
		printf("pa\n");
	}
}

void	pb(t_stack_all *stack_all)
{
	if (stack_all->a_stack)
	{
		add_in_b_stack(stack_all, create_elem(stack_all->a_stack->value));
		if (!stack_all->a_stack->next)
			stack_all->a_stack = NULL;
		else
		{
			stack_all->a_stack = stack_all->a_stack->next;
			stack_all->a_stack->previous = NULL;
		}
		stack_all->a_size--;
		printf("pb\n");
	}
}
