# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 11:49:02 by eghaffar          #+#    #+#              #
#    Updated: 2024/03/31 18:32:14 by eghaffar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
SRC_DIR     := src
BUILD_DIR   := .build
SRCS		:= \
		libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isascii.c \
		libft/ft_isalnum.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_atoi.c	\
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_bzero.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memset.c \
		libft/ft_memset.c\
		libft/ft_strchr.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c\
		libft/ft_strnstr.c\
		libft/ft_split.c\
		libft/ft_striteri.c\
		libft/ft_strmapi.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_substr.c\
		libft/ft_strtrim.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line_utils_bonus.c \
		get_next_line/get_next_line_bonus.c 

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
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
.SILENT: