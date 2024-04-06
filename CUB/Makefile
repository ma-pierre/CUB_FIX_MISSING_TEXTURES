# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:40:03 by eghaffar           #+#    #+#              #
#    Updated: 2024/03/21 11:19:10 by eghaffar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D
SRC_DIR		:= src
BUILD_DIR	:= .build
SRCS		:= 	\
			init/init.c \
			file/read_file.c \
			map/map.c \
			map/map_around.c \
			map/final_map.c \
			map/map_content.c \
			parsing/extension.c \
			parsing/analysis.c \
			parsing/tc_utils.c \
			parsing/main.c \
			parsing/textures_and_colors.c \
			parsing/colorstr_to_int.c \
			parsing/is_map_valid.c \
			utils/utils.c \
			utils/utils2.c \
			utils/debugg.c \
			utils/cleaning.c\
			raycast/raycasting.c\
			raycast/move.c\
			raycast/move_camera.c\
			raycast/keys.c\
			raycast/image.c\
			raycast/minimap.c\
			
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I include -I ./inc -I ./libft -I ./mlx
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
INCLUDES	:= -Ilibft/include

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re