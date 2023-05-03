# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:13:15 by tmoumni           #+#    #+#              #
#    Updated: 2023/05/03 17:34:19 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

SRC = get_next_line.c get_next_line_utils.c so_long.c so_long_utils.c so_long_checks.c 

OBJS = $(SRC:%.c=%.o)

BOLD = \033[1m
END = \033[0m
GREEN = \033[1;32m
RED=\033[1;31m
CYAN = \033[1;36m

all: $(NAME)
	@echo "$(GREEN)Game created successfully!$(END)"

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