#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/09 14:05:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/10/22 17:36:01 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_ls

SRC 		=	srcs/ft_ls.c \
				srcs/ft_lsprocess.c \
				srcs/ft_lsorganize.c \
				srcs/ft_lsoutput.c \
				srcs/ft_lsoutputtime.c \
				srcs/ft_lsgetinfo.c \
				srcs/ft_lslongsize.c \
				srcs/ft_lsprint.c \
				srcs/ft_lsR.c \
				srcs/ft_lsdel.c \
				srcs/utils.c \

EXT			=	Makefile

OBJ			=	$(SRC:.c=.o)

CMP			=	gcc

DEBUG		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror -lpthread 

LIB_DIR		=	-L libft/
LIBS		=	-lft

all : lib $(NAME) compil

$(NAME) : $(OBJ) $(EXT)

compil :
	@$(CMP) $(FLAGS) -o $(NAME) $(SRC) $(LIB_DIR) $(LIBS)
	@echo "ft_ls compiled"

debug_compil :
	@$(CMP) $(FLAGS) $(DEBUG) -o $(NAME) $(SRC) $(LIB_DIR) $(LIBS)
	@echo "ft_ls compiled"

lib :
	@echo "compiling libft..."
	@make -C libft/ --no-print-directory
	@echo "libft compiled"

clean :
	@echo "cleaning objects..."
	@rm -f $(OBJ)
	@rm -rf $(NAME).dSYM
	@make -C libft/ clean --no-print-directory
	@echo "clean done"

fclean : clean
	@rm -f $(NAME)
	@echo "full cleaning libft..."
	@make -C libft/ fclean --no-print-directory
	@echo "fclean done"

re : fclean all

debug : lib $(NAME) debug_compil

.PHONY: $(NAME) all clean fclean re

