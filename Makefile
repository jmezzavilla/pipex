# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 21:40:05 by jmezzavilla       #+#    #+#              #
#    Updated: 2023/09/02 16:48:34 by jealves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =		src/pipex.c\
			src/utils.c\
			src/process.c\
			src/execute.c\

INCLUDES = 	src/pipex.h\

DIR_LIBFT = libft
LIB = $(DIR_LIBFT)/libft.a

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM= rm -f

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o : %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@

all : $(NAME)

lib : 
	@make -C $(DIR_LIBFT)

$(NAME) : lib $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

#bonus : all

clean :
	$(RM) $(OBJ)
	make -C $(DIR_LIBFT) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(DIR_LIBFT) fclean
	
re : fclean all

.PHONY : all clean fclean bonus re