# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 18:51:59 by patrisor          #+#    #+#              #
#    Updated: 2019/09/20 10:02:35 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= hashpipe

# directories
SRCDIR	= ./src
INCDIR	= ./includes
OBJDIR	= ./obj

# src / obj files
SRC		=	main.c \
			read.c \
			bruteforce.c \
			auxiliary.c \
			gateway.c \
			ft_strjoin_size.c \
		  	ft_itoa_hex.c \
		  	errors.c \
		  	io.c \
		  	ssl_stdin_cmd.c \
		  	utils.c \
		  	md5_read.c \
		  	md5_encrypt.c \
		  	sha224.c \
		  	sha256_read.c \
		  	sha256_encrypt.c \
		  	sha256_print.c \
		  	sha512_read.c \
		  	sha512_encrypt.c \
		  	sha512_print.c \
		  	sha384.c \
		  	sha512_224.c \
		  	sha512_256.c \
		  # TODO: Add more source files here

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -ggdb3 #-fsanitize=address

# mlx library
MLX		= ./minilibx_macos/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I $(FT)
FT_LNK	= -L $(FT) -l ft -l pthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
