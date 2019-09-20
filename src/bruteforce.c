/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:40:32 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/20 08:33:38 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashpipe.h"

char	*find_file(char **envp)
{
	static char		file[500];
	int				i;
	int				j;

	while (envp)
	{
		if (ft_strstr(*envp, "PWD") != NULL)
		{
			i = 3;
			j = -1;
			while ((*envp)[++i])
				file[++j] = (*envp)[i];
			break;
		}
		envp++;
	}
	ft_strcat(file, "/includes/passwords.txt");
	return(file);
}
