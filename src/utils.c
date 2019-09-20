/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:36:05 by itiievsk          #+#    #+#             */
/*   Updated: 2019/09/20 10:05:06 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashpipe.h"

int		flags_init(t_flags *flags)
{
	if (flags->q != 1)
		flags->q = 0;
	if (flags->r != 1)
		flags->r = 0;
	flags->s = 0;
	flags->p = 0;
	return (1);
}

void	clean_array(char **arr)
{
	int a;

	a = -1;
	if (arr)
	{
		while (arr[++a])
			free(arr[a]);
		free(arr);
	}
}
