#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/10/04 01:30:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/10/23 21:15:06 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME		=	ft_ls

NOC			=	\033[0m
OKC			=	\033[32m
ERC			=	\033[31m
WAC			=	\033[33m

CMP			=	gcc

DEBUG		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror

SRCDIR =	./obj/
LFTDIR =	./libft/
INCDIR =	./includes/
SRCDIR =	./srcs/

OBJNAME =	$(SRC_NAME:.c=.o)
INCNAME =	ft_ls.h
SRCNAME =	ft_ls.c \
			ft_lsprocess.c \
			ft_lsprocessdir.c \
			ft_lsorganize.c \
			ft_lsoutput.c \
			ft_lsoutputtime.c \
			ft_lsgetinfo.c \
			ft_lslongsize.c \
			ft_lsprint.c \
			ft_lsR.c \
			ft_lsdel.c \
			utils.c

SRC		= 	$(addprefix $(SRCDIR),$(SRCNAME))
OBJ		= 	$(addprefix $(SRCDIR),$(OBJNAME))
INC		= 	$(addprefix $(INCDIR),$(INCNAME))

EXT		=	Makefile


LIB_DIR		=	-L libft/
LIBS		=	-lft


#/////////////////////
all: $(NAME)
	
$(NAME): $(OBJ)
		@echo
		@make -C $(LFTDIR)
		@$(CMP) -o $(NAME) -L $(LFTDIR) -lft $^ -o $@
		@echo "$(OKC)$(NAME):\t\t$(NAME) READY$(NOC)"
		@echo "¯\_ツ_/¯"

$(SRCDIR)%.o: $(SRCDIR)%.c
		@mkdir -p $(SRCDIR) 2> /dev/null || true
		#@$(CMP) -c -o $@ $< -I $(INC) $(FLAGS)
		@$(CMP) $(FLAGS) $(INC) -o $@ -c $<
		@echo -n .

clean:
		@make -C $(LFTDIR) clean
		@rm -rf $(SRCDIR)
		@echo "$(WAC)$(NAME):\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
		@make -C $(LFTDIR) fclean
		@rm -f $(NAME)
		@echo "$(WAC)$(NAME):\t\tRemoving $(NAME) executables$(NOC)"

re: fclean all

.PHONY: $(NAME) all clean fclean re
#//////////////////
#all : $(NAME)
#$(NAME) :
#	$(OBJ)
#	@make -C libft/ --no-print-directory
#	@printf "\033[31mCompilation $(NAME):\033[0m"
#	@$(CMP) $(FLAGS) -o $(NAME) -c $@ $^ $(LIB_DIR) $(LIBS)
#	@printf "\033[34m done!\n\033[0m"
#
#$(OBJ): $(INCL)
#
#clean :
#	@rm -f $(OBJ)
#	@rm -rf $(NAME).dSYM
#	@make -C libft/ clean --no-print-directory
#
#fclean : clean
#	@rm -f $(NAME)
#	@make -C libft/ fclean --no-print-directory
#
#re : fclean all
#
#debug :
#	@make -C libft/ --no-print-directory
#	@printf "\033[31mCompilation debug mode $(NAME):\033[0m"
#	@$(CMP) $(FLAGS) $(DEBUG) -o $(NAME) $(SRC) $(LIB_DIR) $(LIBS)
#	@printf "\033[34m done!\n\033[0m"
#
#silent :
#	@:
#
#

