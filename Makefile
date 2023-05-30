# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/05/30 18:49:32 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SOURCES = pipex.c ft_pipe.c ft_execve_path.c ft_error.c ft_parser.c ft_pipex_utils.c
SOURCES_BONUS = pipex_bonus.c ft_pipe_bonus.c ft_execve_path_bonus.c ft_error_bonus.c ft_parser_bonus.c ft_pipex_utils_bonus.c

LIBFT = libft.a
LIBFTPRINTF = libftprintf.a
LIBGNL = libgnl.a

LIB = ft 
LIB_DIR = libft

LIB2 = ftprintf
LIB_DIR2 = ft_printf

LIB3 = gnl
LIB_DIR3 = get_next_line

# **************************************************************************** #

INCS = $(INCLUDES)
LDLIBS = -l $(LIB) $(LIB2) $(LIB3)

ifdef WITH_BONUS
	SRC_DIR = srcs_bonus
	OBJ_DIR = objs_bonus
	SRCS = $(SOURCES_BONUS)
	OBJS = $(SOURCES_BONUS:.c=.o)
else
	SRC_DIR = srcs
	OBJ_DIR = objs
	SRCS = $(SOURCES)
	OBJS = $(SOURCES:.c=.o)
endif

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJS))
INCS := $(addprefix $(SRC_DIR)/, $(INCS))
LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))
LIBFTPRINTF := $(addprefix $(LIB_DIR2)/, $(LIBFTPRINTF))
LIBGNL := $(addprefix $(LIB_DIR3)/, $(LIBGNL))

# **************************************************************************** #

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = crus
RMFLAGS = -rf

LDFLAGS = -L $(LIB_DIR) $(LIB_DIR2)

# Commands ******************************************************************* #

all : $(NAME)

bonus :
	make WITH_BONUS=1 $(NAME)

clean :
	$(RM) $(RMFLAGS) objs objs_bonus */*.a */*.o */*/*.o

fclean : 
	$(MAKE) clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# Dependency ***************************************************************** #

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)
	$(CC) $(CFLAGS) $(OBJS) -I $(SRC_DIR) -o $(NAME) -L $(LIB_DIR) -L $(LIB_DIR2) -L $(LIB_DIR3) -l $(LIB) -l $(LIB2) -l $(LIB3)

$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(LIBFTPRINTF): 
	$(MAKE) -j3 -C $(LIB_DIR2) all

$(LIBGNL): 
	$(MAKE) -j3 -C $(LIB_DIR3) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -I $(SRC_DIR) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# **************************************************************************** #

