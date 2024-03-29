/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:48:52 by itiievsk          #+#    #+#             */
/*   Updated: 2019/09/20 09:59:22 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashpipe.h"

static uint32_t	swap_endian(uint32_t state)
{
	uint32_t	ret;

	ret = ((state >> 24) & 0xff) |
			((state << 8) & 0xff0000) |
			((state >> 8) & 0xff00) |
			((state << 24) & 0xff000000);
	return (ret);
}

char			*ft_itoa_hex(uint32_t state[], int size, int i, char end)
{
	char		*ret;
	int			j;
	uint32_t	r;
	uint32_t	temp;

	ret = ft_strnew(size);
	r = 0x10000000;
	while (i < size)
	{
		temp = (end == 'L' ? swap_endian(state[i / 8]) : state[i / 8]);
		j = 0;
		while (j < 8)
		{
			ret[i] = HEX[temp / (r >> (4 * j))];
			temp = temp % (r >> (4 * j));
			j++;
			i++;
		}
	}
	return (ret);
}

char			*ft_itoa_hex_512(uint64_t state[], int size, int i, char end)
{
	char		*ret;
	int			j;
	uint64_t	r;
	uint64_t	temp;

	ret = ft_strnew(size);
	r = 0x1000000000000000;
	while (i < size)
	{
		temp = (end == 'L' ? 0 : state[i / 16]);
		j = 0;
		while (j < 16)
		{
			ret[i] = HEX[temp / (r >> (4 * j))];
			temp = temp % (r >> (4 * j));
			j++;
			i++;
		}
	}
	return (ret);
}
