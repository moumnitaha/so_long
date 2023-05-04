# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:13:15 by tmoumni           #+#    #+#              #
#    Updated: 2023/05/04 16:40:33 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c so_long.c so_long_utils/so_long_utils.c\
so_long_utils/so_long_checks.c so_long_utils/so_long_validation.c ft_printf/ft_printf.c ft_printf/ft_putnbr.c\
ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_puthex.c ft_printf/ft_putunbr.c ft_printf/ft_putptr.c

OBJS = $(SRC:%.c=%.o)

BOLD = \033[1m
GREEN = \033[1;32m
RED=\033[1;31m
CYAN = \033[1;36m
END = \033[0m

all: $(NAME)
	@echo "\n$(GREEN)[[Game created successfully!]]$(END)\n"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(CYAN)Compiling:$(END)" $< "..."

$(NAME): $(SRC) $(HEADER) $(OBJS)
	@echo "Creating $(GREEN)Game...$(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "\n$(RED)[ Object files deleted successfully! ]$(END)\n"

fclean:
	@rm -f $(NAME) $(OBJS)
	@echo "\n$(RED)[ All files deleted successfully! ]$(END)\n"

re: fclean all

.PHONY: all clean fclean re