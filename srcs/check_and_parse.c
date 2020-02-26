/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:48:52 by taegon-i          #+#    #+#             */
/*   Updated: 2020/02/20 15:52:08 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		add_in_stack(t_stack_all *stack, t_stack *elem)
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
			// tmp = elem;
			// elem = stack->a_stack;
			// elem = tmp;
			//
			//
			tmp = stack->a_stack;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = elem;
			elem->previous = tmp;





			// tmp = stack->a_stack->previous;
			// elem->previous = tmp;
			// tmp->next = elem;
			// elem->next = stack->a_stack;
			// stack->a_stack->previous = elem;
		}
		stack->a_size++;
		stack->a_stack->index = stack->a_size;

	}
}

void	parse_array(t_stack_all *stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
			error_message(4);
		add_in_stack(stack, create_elem(ft_atoi(argv[i++])));

	}
}

t_stack		*create_elem(int number)
{
	t_stack	*new;

	if (!(new = (t_stack *)ft_memalloc(sizeof(t_stack))))
		error_message(3);

	new->value = number;
	new->previous = NULL;
	new->next = NULL;
	new->index = 0;
	return (new);
}

void	parse_string(t_stack_all *stack, char *str)
{
	char	**numbers;
	size_t	i;


	numbers = ft_strsplit(str, ' ');
	i = 0;
	// printf("numbers[0] = %s\n", numbers[0]);
	// printf("numbers[1] = %s\n", numbers[1]);
	// printf("numbers[2] = %s\n", numbers[2]);
	// printf("atoi(ав) = %d\n", ft_atoi("ав"));

	while (numbers[i])
	{
		if (!ft_isnum(numbers[i], 10))
			error_message(2);
		if (!ft_isint(numbers[i]))
			error_message(4);
		add_in_stack(stack, create_elem(ft_atoi(numbers[i++])));
	}
	ft_strsplit_free(&numbers);
}


t_stack_all	*contain_in_a(int argc, char *argv[])
{
	t_stack_all *stack;

	if (!(stack = (t_stack_all *)ft_memalloc(sizeof(t_stack_all))))
		error_message(3);
	stack->a_stack = NULL;
	stack->a_size = 0;
	stack->b_stack = NULL;
	stack->b_size = 0;
	if (argc == 2)
		parse_string(stack, argv[1]);
	else
		parse_array(stack, argc, argv);

	if (!stack->a_size)
		error_message(2);
	return (stack);
}
