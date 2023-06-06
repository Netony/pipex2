# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/06/06 16:08:53 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SOURCES = ft_execve_path.c \
		  error.c parser.c free.c dup2_file.c dup2_pipe.c \
		  pipex_utils.c
SOURCES_TESTS = test.c
SOURCES_MANDA = pipex.c ft_pipe.c 
SOURCES_BONUS = pipex_bonus.c ft_pipe_bonus.c parser_bonus.c error_bonus.c

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

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = srcs

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJS_MANDA = $(addprefix $(OBJ_DIR)/, $(SOURCES_MANDA:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))
OBJS_TESTS = $(addprefix $(OBJ_DIR)/, $(SOURCES_TESTS:.c=.o))

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))
SRCS_MANDA := $(addprefix $(SRC_DIR)/, $(SOURCES_MANDA))
SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(SOURCES_BONUS))
SRCS_TESTS := $(addprefix $(SRC_DIR)/, $(SOURCES_TESTS))

INCS := $(addprefix $(INC_DIR)/, $(INCS))

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

# Commands ******************************************************************* #

all bonus test :
	$(CC) $(CFLAGS) $^ -I $(INC_DIR) -o $(NAME) -L $(LIB_DIR) -L $(LIB_DIR2) -L $(LIB_DIR3) -l $(LIB) -l $(LIB2) -l $(LIB3)

clean :
	$(RM) $(RMFLAGS) objs objs_bonus */*.a */*.o */*/*.o

fclean : 
	$(MAKE) clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

all : $(OBJS) $(OBJS_MANDA) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)

bonus : $(OBJS) $(OBJS_BONUS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)

test : $(OBJS) $(OBJS_TESTS) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)

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

