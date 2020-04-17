/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:52:41 by jcremin           #+#    #+#             */
/*   Updated: 2020/04/17 13:52:43 by jcremin          ###   ########.fr       */
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
