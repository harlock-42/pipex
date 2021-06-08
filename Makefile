# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:14:57 by tallaire          #+#    #+#              #
#    Updated: 2021/05/27 18:15:03 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m


NAME		=	pipex

CC		=	clang

RM		=	rm -rf

CP		=	cp -r

CFLAGS		=	-Werror -Wextra -Wall -c

          #############
         ###############
        ####         ####
        ####  PIPEX  ####
        ####         ####
         ###############
          #############

SRC		+=	exec.c
SRC		+=	main.c
SRC		+=	free_tab.c
SRC		+=	get_arg.c
SRC		+=	get_path.c
SRC		+=	lst_to_tab.c

	########
	# LIST #
	########

SRC		+=	lst_add_back.c
SRC		+=	lst_free.c
SRC		+=	lst_print.c
SRC		+=	lst_print_binary.c
SRC		+=	lst_size.c

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/list
vpath %.c srcs/utils

OBJ			=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

LIBFT_NAME		=	libft.a

HEADER_NAME		=	pipex.h

LIB_PATH		=	./.lib

HEADER_PATH		=	./include

LIBFT_PATH		=	./libft

LIBFT_SRC		=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

LIBFT			=	$(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

HEADER			=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

HEADER_CHECK		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME_CHECK))

all: $(NAME) $(HEADER) Makefile

$(NAME): $(LIB_PATH) $(LIBFT_SRC) $(LIBFT) $(OBJ_PATH) $(OBJ)
	   @$(CC) -I$(HEADER_PATH)/ -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$<		[$(C_GREEN)OK$(C_END)]"

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER) Makefile
	@$(CC) -I$(HEADER_PATH)/ $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@$(CP) $(LIBFT_SRC) $(LIB_PATH)

$(LIBFT_SRC):
	@(cd $(LIBFT_PATH) && $(MAKE))

$(LIB_PATH):
	@mkdir $(LIB_PATH)

clean:
	@$(RM) $(OBJ_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) clean)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) fclean)

re: fclean all
