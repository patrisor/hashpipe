/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashpipe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 03:52:46 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/20 10:54:42 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keycode_mac.h"
# include "sha512.h"
# include <errno.h>
# include <stdbool.h>

# define FUNCTIONS 7
# define FUNC_NAME 10
# define FLAGS "pqrs"
# define MAX 9223372036854775807
# define BUF 10000
# define HEX "0123456789abcdef"
# define NUM_OF_FLAGS 2

typedef struct			s_hash_pipe
{
	char	flag[2][20];
	char	words[10000];
}						t_hash_pipe;

// HASHING OBJECTS

typedef struct	s_ssl_func
{
	char		func[FUNC_NAME];
	char		type[3];
	void		(*handler)(int, char**);
}				t_ssl_func;

typedef struct	s_file
{
	char		*target;
	char		*string;
	int         fd;
	int			p;
	int			q;
	int			r;
	int			s;
}				t_file;

// HASHPIPE BRUTEFORCE

int			read_file(char *file, t_hash_pipe **ret);
int			parse_flag(char *av, t_hash_pipe **ret);
int			*ft_find_str_occur(char* pat, char* txt, int size);
int			ft_find_num_str(char* pat, char* txt);
char		*find_file(char **envp);

// HASHING ALGORITHMS

int				gateway(int argc, char **argv);
void			init_functions(t_ssl_func handler[FUNCTIONS]);
void			stdin_cmd(int argc, int i, t_ssl_func handler[], bool no_error);
void			md5(int argc, char **argv);
void			sha256(int argc, char **argv);
void			sha224(int argc, char **argv);
void			sha512(int argc, char **argv);
void			sha512224(int argc, char **argv);
void			sha512256(int argc, char **argv);
void			sha384(int argc, char **argv);
int				flags_init(t_flags *flags);
void			wrong_argument(t_ssl_func handler[], char **argv, int i,
				bool stdin);
char			*ssl_read_stdin(size_t *len, int i, t_flags *flags);
char			*ssl_read_file(char *arg, size_t *length, char f[],
				char **file);
char			*ft_strjoin_size(char const *s1, char const *s2, size_t size);
void			usage(void);
void			check_extra_flags(t_flags *flags, char flag, char f[]);
void			ssl_s_error(t_flags *flags, char f[]);
void			ssl_err_flag(char ch, t_flags *flags, char f[]);
char			*ft_itoa_hex(uint32_t state[], int size, int i, char end);
char			*ft_itoa_hex_512(uint64_t state[], int size, int i, char end);
void			clean_array(char **arr);

#endif
