# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 22:06:41 by lserghin          #+#    #+#              #
#    Updated: 2025/03/06 00:18:44 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft -Lminilibx-linux -lmlx -lX11 -lXext -lm

INCLUDES = -Iinclude -Iminilibx-linux
INCLUDES_BONUS = -Iinclude_bonus -Iminilibx-linux

SRCS_DIR = source
OBJS_DIR = object

SRCS_BONUS_DIR = source_bonus
OBJS_BONUS_DIR = object_bonus

SRC_FILES = main.c map_validation.c player.c render.c parse_map.c inputs.c assets.c cleanup.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

SRC_FILES_BONUS = main_bonus.c map_validation_bonus.c player_bonus.c render_bonus.c parse_map_bonus.c \
				inputs_bonus.c assets_bonus.c cleanup_bonus.c enemy_bonus.c
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, $(SRC_FILES_BONUS))
OBJS_BONUS = $(SRCS_BONUS:$(SRCS_BONUS_DIR)/%.c=$(OBJS_BONUS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Project successfully built!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "Bonus project successfully built!"
	
$(OBJS_BONUS_DIR)/%.o: $(SRCS_BONUS_DIR)/%.c
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@
clean:
	@rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@make -C libft clean
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C libft fclean
	@echo "Executable and libraries removed."

re: fclean all

.PHONY: all clean fclean re bonus
