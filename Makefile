# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:13:15 by tmoumni           #+#    #+#              #
#    Updated: 2023/05/14 14:16:48 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h
B_HEADER = bonus/so_long_bonus.h

SRCS = so_long.c\
	sl_utils/alloc_free_tab.c sl_utils/ft_bzero.c sl_utils/sl_count_clctbls.c sl_utils/sl_count_P_E.c\
	sl_utils/sl_exit_game.c sl_utils/sl_init_game.c sl_utils/sl_key_press.c sl_utils/sl_main_check.c sl_utils/sl_moves.c\
	sl_utils/sl_path_to_C.c sl_utils/sl_path_to_exit.c sl_utils/sl_player_pos.c sl_utils/sl_put_imgs.c sl_utils/sl_read_map.c\
	sl_utils/sl_rect_map.c sl_utils/sl_draw_imgs.c sl_utils/sl_valid_chars.c sl_utils/sl_valid_ext.c sl_utils/sl_valid_walls.c sl_utils/sl_win_game.c\
	sl_utils/sl_path_algo.c sl_utils/sl_valid_xpm.c sl_utils/sl_escape_game.c\
	ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putchar.c ft_printf/ft_putstr.c\
	ft_printf/ft_puthex.c ft_printf/ft_putunbr.c ft_printf/ft_putptr.c\
	ft_itoa/ft_itoa.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c

B_SRCS = bonus/so_long_bonus.c\
	bonus/alloc_free_tab_bonus.c bonus/ft_bzero_bonus.c bonus/sl_count_clctbls_bonus.c bonus/sl_count_P_E_bonus.c\
	bonus/sl_exit_game_bonus.c bonus/sl_init_game_bonus.c bonus/sl_key_press_bonus.c bonus/sl_main_check_bonus.c bonus/sl_moves_bonus.c\
	bonus/sl_path_to_C_bonus.c bonus/sl_path_to_exit_bonus.c bonus/sl_player_pos_bonus.c bonus/sl_put_imgs_bonus.c bonus/sl_read_map_bonus.c\
	bonus/sl_rect_map_bonus.c bonus/sl_draw_imgs_bonus.c bonus/sl_valid_chars_bonus.c bonus/sl_valid_ext_bonus.c bonus/sl_valid_walls_bonus.c\
	bonus/sl_win_game_bonus.c bonus/sl_path_algo_bonus.c bonus/sl_valid_xpm_bonus.c bonus/sl_escape_game_bonus.c\
	ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putchar.c ft_printf/ft_putstr.c\
	ft_printf/ft_puthex.c ft_printf/ft_putunbr.c ft_printf/ft_putptr.c\
	ft_itoa/ft_itoa.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

BOLD = \033[1m
GREEN = \033[1;32m
RED=\033[1;31m
CYAN = \033[1;36m
END = \033[0m

all: $(NAME)
	@echo "\n$(GREEN)[[Game created successfully!]]$(END)\n"

%.o : %.c $(HEADER) $(B_HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(CYAN)Compiling:$(END)" $< "..."

$(NAME): $(SRCS) $(OBJS) $(HEADER)
	@echo "Creating $(GREEN)Game...$(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

bonus: $(B_SRCS) $(B_OBJS) $(B_HEADER)
	@echo "Creating $(GREEN)Bonus Game...$(END)"
	@$(CC) $(CFLAGS) $(B_OBJS) $(MFLAGS) -o $(BONUS)
	@echo "\n$(GREEN)[[Game with bonus created successfully!]]$(END)\n"

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@echo "\n$(RED)[ Object files deleted successfully! ]$(END)\n"

fclean:
	@rm -f $(NAME) $(OBJS) $(BONUS) $(B_OBJS)
	@echo "\n$(RED)[ All files deleted successfully! ]$(END)\n"

re: fclean all

.PHONY: all bonus clean fclean re