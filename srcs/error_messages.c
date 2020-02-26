/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:25:04 by taegon-i          #+#    #+#             */
/*   Updated: 2020/02/20 11:10:11 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(int n)
{
	if (n == 1)
		printf("ERROR: need 1 arguments\n");
	if (n == 2)
		printf("ERROR: arguments is not numbers\n");
	if (n == 3)
		printf("ERROR: malloc error\n");
	if (n == 4)
		printf("ERROR: arguments is not INT's\n");
	exit(0);
}
