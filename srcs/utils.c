/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:53:58 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:53:59 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void count_sred(t_stack_all *stack)
{
	t_stack *temp;
	int count;

	count = 0;
	temp = stack->a_stack;
	while (temp)
	{
		count += temp->value;
		temp = temp->next;
	}
	stack->sred = count / stack->a_size;
}

void	numbering_stack(t_stack *stack)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		tmp->number = i;
		i++;
		tmp = tmp->next;
	}
}

void	calc_chank_size(t_stack_all *stack_all)
{
	stack_all->chank_size = stack_all->chank_diap / num_chanks(stack_all);
	if (stack_all->chank_diap % num_chanks(stack_all) != 0)
		stack_all->chank_size += 1;
}

int		num_chanks(t_stack_all *stack_all)
{
	if (stack_all->a_size >= 6 && stack_all->a_size <= 49)
		return (2);
	else if (stack_all->a_size >= 50 && stack_all->a_size <= 99)
		return (3);
	else if (stack_all->a_size >= 100 && stack_all->a_size <= 149)
		return (4);
	else if (stack_all->a_size >= 150 && stack_all->a_size <= 199)
		return (5);
	else if (stack_all->a_size >= 200 && stack_all->a_size <= 249)
		return (6);
	else if (stack_all->a_size >= 250 && stack_all->a_size <= 299)
		return (7);
	else if (stack_all->a_size >= 300 && stack_all->a_size <= 349)
		return (8);
	else if (stack_all->a_size >= 350 && stack_all->a_size <= 399)
		return (9);
	else if (stack_all->a_size >= 400 && stack_all->a_size <= 499)
		return (10);
	else if (stack_all->a_size >= 500)
		return (11);
	else
		return (1);
}

void	calc_diap_chank(t_stack_all *stack_all)
{
	if (stack_all->min < 0 && stack_all->max < 0)
	{
		stack_all->chank_diap = -(stack_all->min) - -(stack_all->max) + 1;
	}
	else if (stack_all->min < 0 && stack_all->max > 0)
	{
		stack_all->chank_diap = stack_all->max + -(stack_all->min) + 1;
	}
	else if (stack_all->min > 0 && stack_all->max > 0)
	{
		stack_all->chank_diap = stack_all->max - stack_all->min + 1;
	}
}
void	min_and_max(t_stack_all *stack_all)
{
	t_stack *tmp;

	stack_all->min = stack_all->a_stack->value;
	stack_all->max = stack_all->a_stack->value;
	tmp = stack_all->a_stack;
	while (tmp != NULL)
	{
		if (tmp->value < stack_all->min)
			stack_all->min = tmp->value;
		if (tmp->value > stack_all->max)
			stack_all->max = tmp->value;
		tmp = tmp->next;
	}

}

void	rrx(t_stack_all *stack_all, t_stack *stack)
{
	t_stack *tmp;
	t_stack *tmp_last;

	tmp = NULL;
	tmp_last = NULL;
	if (stack)
	{
		if (stack->next)
		{
			if (stack->next->next)
			{
				tmp = stack;
				tmp_last = stack->last;

				while (tmp->next != stack->last)
					tmp = tmp->next;
				stack->last = tmp;

				stack->last->next = NULL;

				tmp_last->next = stack;
				tmp_last->previous = NULL;
				stack = tmp_last;
			}
			else
			{
				stack_all->check = 1;
				sa(stack_all);
				stack_all->check = 0;
			}
		}
		else
			stack_all->check = 1;
	}
	else
		stack_all->check = 1;
	ft_putnbr(stack->last->value);
}
