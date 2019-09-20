/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:27:28 by itiievsk          #+#    #+#             */
/*   Updated: 2019/09/20 10:21:32 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# define RR(a, b) (((a) >> (b)) | ((a) << (32 - (b))))
# define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define E0(x) (RR(x, 2) ^ RR(x, 13) ^ RR(x, 22))
# define E1(x) (RR(x, 6) ^ RR(x, 11) ^ RR(x, 25))
# define S0(x) (RR(x, 7) ^ RR(x, 18) ^ ((x) >> 3))
# define S1(x) (RR(x, 17) ^ RR(x, 19) ^ ((x) >> 10))

#include "md5.h"

typedef struct	s_sha256_ctx
{
	char		func[10];
	char		*file;
	uint32_t	state[8];
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	size_t		len;
	int			argc;
	int			blocks;
	int			targets;
}				t_sha256_ctx;

int				sha256_encrypt(char *str, t_flags *flags, t_sha256_ctx *ctx);
void			sha256_parse_targets(int argc, char **argv, t_flags *flags,
				t_sha256_ctx *ctx);
void			sha256_abcd_assign(t_sha256_ctx *ctx, char order);
void			sha256_transform(uint32_t *input, t_sha256_ctx *ctx, int i,
				int rnd);
void			sha256_process(uint32_t **input, t_sha256_ctx *ctx);
void			sha256_finalize(char *str, uint32_t **input, t_sha256_ctx *ctx);
void			sha256_print(char *str, t_flags *flags, t_sha256_ctx *ctx);
int				sha224_encrypt(char *str, t_flags *flags, t_sha256_ctx *ctx);
void			sha224_print(char *str, t_flags *flags, t_sha256_ctx *ctx);
#endif
