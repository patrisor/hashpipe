/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:29:07 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/20 08:50:59 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashpipe.h"

// TODO: To make smaller and more efficient, assign as static array with M and N values stored
int		*ft_find_str_occur(char* pat, char* txt, int size)
{
	int		*ret;
    int		i;
	int		j;
	int		k;
	int		M;
    int		N;

	i = -1;
	k = -1;
	M = ft_strlen(pat);
	N = ft_strlen(txt);
	ret = (int *)malloc(sizeof(int) * size);
	while (++i <= N - M)
	{
        j = -1;
		while (++j < M)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
			ret[++k] = i;
    }
	return(ret);
}

int		ft_find_num_str(char* pat, char* txt)
{
	int		ret;
    int		i;
	int		j;
	int		M;
    int		N;

	i = -1;
	ret = 0;
	M = ft_strlen(pat);
	N = ft_strlen(txt);
	while (++i <= N - M)
	{
        j = -1;
		while (++j < M)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
			ret++;
    }
	return(ret);
}
