/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:50:27 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/20 10:54:38 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashpipe.h"

// TODO: FIX LEAKS
int		read_file(char *file, t_hash_pipe **ret)
{
	char			*line;
	int				fd;
	int				hit;
	int				i;

	hit = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = -1;
		ft_strcat((*ret)->words, line);
		while (++i < (int)ft_strlen(line))
			(line[i] == '}') ? ++hit : 0;
		if (hit >= 2)
			break;
		free(line);
	}
	if (hit == 0)
		return (-1);
	ft_strcat(ft_strcat((*ret)->words, ft_itoa(ft_find_num_str("passwd", line))), "\0");
	close(fd);
	return(0);
}

int		parse_flag(char *av, t_hash_pipe **ret)
{
	int				i;
	int				hit;
	char			flags[NUM_OF_FLAGS][20] = {"sha256", "sha512"};
	
	i = -1;
	hit = 0;
	while (++i < NUM_OF_FLAGS) 
	{
		if (ft_strcmp(flags[i], av) == 0) 
		{
			ft_strcpy((*ret)->flag[0], ((ft_strcmp(flags[i], "sha256") == 0) ? "sha256" : "sha512"));
			ft_strcpy((*ret)->flag[1], ((ft_strcmp(flags[i], "sha256") == 0) ? ";s:64:" : ";s:128:"));
			hit++;
		}
	}	
	return (0);
}
