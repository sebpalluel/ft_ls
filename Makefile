#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/10/04 01:30:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/10/24 14:59:46 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME		=	ft_ls

NOC			=	\033[0m
DEBC		=	\033[36m
OKC			=	\033[32m
ERC			=	\033[31m
WAC			=	\033[33m

CMP			=	gcc

DEBUG_F		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror

OBJDIR		=	./obj/
LFTDIR		=	./libft/
INCDIR		=	./includes/
SRCDIR		=	./srcs/

OBJNAME		=	$(SRCNAME:.c=.o)
INCNAME		=		ft_ls.h \
					ft_ls_define.h \
					ft_ls_struct.h
SRCNAME		=		ft_ls.c \
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
OBJ		= 	$(addprefix $(OBJDIR),$(OBJNAME))
INC		= 	$(addprefix -I,$(INCDIR),$(INCNAME))

EXT		=	Makefile

debug : all

all: $(NAME) $(EXT)

$(NAME): $(OBJ)
	@echo
ifneq (,$(filter debug,$(MAKECMDGOALS)))
	@echo "$(DEBC)$(NAME):\t\t$(NAME) DEBUG MODE$(NOC)"
	@echo "$(DEBC)⤜(ʘvʘ)⤏$(NOC)"
	@make debug -C $(LFTDIR)
	@$(CMP) $(FLAGS) $(DEBUG_F) -o $(NAME) -L $(LFTDIR) -lft $^ -o $@
else
	@make -C $(LFTDIR)
	@$(CMP) $(FLAGS) -o $(NAME) -L $(LFTDIR) -lft $^ -o $@
	@echo "$(OKC)$(NAME):\t\t$(NAME) READY$(NOC)"
	@echo "$(OKC)¯\_ツ_/¯$(NOC)"
endif

$(OBJDIR)%.o: $(SRCDIR)%.c
ifneq (,$(filter debug,$(MAKECMDGOALS)))
	@mkdir -p $(OBJDIR) 2> /dev/null || true
	@$(CMP) -c -o $@ $< $(INC) $(FLAGS) $(DEBUG_F)
	@echo -n .
else
	@mkdir -p $(OBJDIR) 2> /dev/null || true
	@$(CMP) -c -o $@ $< $(INC) $(FLAGS)
	@echo -n .
endif

clean:
	@make -C $(LFTDIR) clean
	@rm -rf $(OBJDIR)
	@echo "$(WAC)$(NAME):\t\tRemoving OBJ dir: ./obj/$(NOC)"

fclean: clean
	@make -C $(LFTDIR) fclean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME):\t\tRemoving $(NAME) executables$(NOC)"

re: fclean all

.PHONY: $(NAME) all clean fclean re
