# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:13:15 by tmoumni           #+#    #+#              #
#    Updated: 2023/05/13 16:37:39 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

SRC = so_long.c\
	sl_utils/alloc_free_tab.c sl_utils/ft_bzero.c sl_utils/sl_count_clctbls.c sl_utils/sl_count_P_E.c sl_utils/sl_draw_tab.c\
	sl_utils/sl_exit_game.c sl_utils/sl_init_game.c sl_utils/sl_key_press.c sl_utils/sl_main_check.c sl_utils/sl_moves.c\
	sl_utils/sl_path_to_C.c sl_utils/sl_path_to_exit.c sl_utils/sl_player_pos.c sl_utils/sl_put_imgs.c sl_utils/sl_read_map.c\
	sl_utils/sl_rect_map.c sl_utils/sl_draw_imgs.c sl_utils/sl_valid_chars.c sl_utils/sl_valid_ext.c sl_utils/sl_valid_walls.c sl_utils/sl_win_game.c\
	sl_utils/sl_path_algo.c sl_utils/sl_valid_xpm.c sl_utils/sl_escape_game.c\
	ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putchar.c ft_printf/ft_putstr.c\
	ft_printf/ft_puthex.c ft_printf/ft_putunbr.c ft_printf/ft_putptr.c\
	ft_itoa/ft_itoa.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c\

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