/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:49:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/20 10:54:22 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashpipe.h"

int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

char	*print_usage(void)
{
	return ("usage: ./hashpipe [hash] [hash_file]\n\n \
	HASHES:\n\t- sha256\n\t- sha512\n");
}

int		main(int ac, char **av, char **envp)
{
	t_hash_pipe		*hp;

	if (ac <= 2 || ac > 3)
		return (die(print_usage()));	
	if ((hp = (t_hash_pipe *)malloc(sizeof(t_hash_pipe))) == NULL)
		return(die("error: failed to allocate hash_pipe"));
	if (parse_flag(av[1], &hp) == -1)
		return(die("error: flag is invalid"));
	if (read_file(av[2], &hp) == -1)
		return(die("error: file is invalid"));
	
	// TODO: Bruteforce wrapper function (loop through number of hashes in passwd file)
	/*
	int		num_hashes;
	int     i;
	num_hashes = ft_atoi(&(words[ft_strlen(words) - 1]));
	//char	hashes[ft_atoi(&(words[ft_strlen(words) - 1]))];
	i = -1;
	while (words[++i] != '\0')
		ft_putchar(words[i]);
	ft_putstr("\n");
	*/
	
	/* TODO: Uncomment for Leak Test
	ft_putnbr(getpid());
	ft_putstr("\n");
	sleep(5);
	*/

	// TODO: Implement Wrapper Function into Bruteforce
	//char			param[4][20];
	char			*line;
	int				fd;

	// WRAP
	char **param = (char **)malloc(sizeof(char *) * 4);
	param[0] = av[0];
	param[1] = hp->flag[0];
	param[2] = "-qs";
	fd = open(find_file(envp), O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		param[3] = line;
		ft_putstr(line);
		ft_putstr("\t:\t");
		gateway(4, param);
		ft_putstr("\n");
		free(line);
	}
	close(fd);
	// WRAP

	free(hp);
	free(param);
	return (0);
}
