# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annavm <annavm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 20:30:29 by annavm            #+#    #+#              #
#    Updated: 2024/05/28 13:42:45 by annavm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED		= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
ORANGE		= \033[38;5;222m
GREEN_BR	= \033[38;5;118m
YELLOW_BR	= \033[38;5;227m
PINK_BR		= \033[38;5;206m
BLUE_BR		= \033[38;5;051m

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS 	=	rcs
RM			=	rm -rf

SRC			=	ft_common.c \
				ft_decimal_integer.c \
				ft_flags_handle.c \
				ft_init.c \
				ft_print_hexadecimal.c \
				ft_print_pointer.c \
				ft_print_unsigned_decimal.c \
				ft_printf.c \
				ft_single_character.c \
				ft_string.c \
				ft_what_the_flag.c

OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

all: $(NAME)

bonus:				all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW_BR)\n   Getting ft_printf ready\n$(DEF_COLOR)"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⣋⣉⡙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠮⡞⠁⠀⠈⢢⠷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⢠⢤⣇⠀⡇⠀⠀⠀⢸⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⡏⢰⠙⠚⢧⣀⢀⣠⠞⠓⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⡸⠀⡎⠀⣀⡤⠏⠉⠧⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⢠⠃⢰⡵⠊⠁⠀⠀⠀⠀⠀⠈⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⢸⡀⠀⣀⡠⡆⠀⠀⠀⠀⠀⣆⠀⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⡇⠀⠀⠀⠀⠀⡏⢣⡀⠘⣄⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢸⠀⠙⢤⡈⢦⡀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⠀⢠⠖⣒⣶⠖⠒⠒⠒⠲⠷⣒⠒⠒⠒⠒⣺⣶⠖⠒⠓⢤⣹⠶⣒⠲⡄⠀⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⠀⢠⠏⣞⣟⠉⠀⣖⠒⣲⠀⠀⠈⣳⠀⠀⡎⡞⠉⠀⣖⢒⣢⠀⠀⠈⡇⠹⡄⠀ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⢠⠏⠀⠘⠪⢅⣀⣀⠉⣀⣀⡠⠔⠁⠀⠀⠙⠮⣇⣀⣀⠉⣀⣀⡤⠖⠁⠀⠹⡄ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⡟⠒⠒⠒⠒⠒⠒⠓⠛⠚⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠚⠛⠛⠒⠒⠒⠒⠒⠒⢻ $(DEF_COLOR)"
	@echo "$(GREEN_BR)⡇$(DEF_COLOR)   $(BLUE_BR)Getting libft ready!$(DEF_COLOR)     $(GREEN_BR)⢸$(DEF_COLOR)"
	@echo "$(GREEN_BR)⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸$(DEF_COLOR)"
	@make -s -C $(LIBFT_PATH)

clean:
	@make -s -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)
	@echo "$(PINK_BR)..........Removing libft$(DEF_COLOR)"

fclean: clean
	@make -s -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "$(ORANGE).....ALL binaries cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

