# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 02:31:28 by maaugust          #+#    #+#              #
#    Updated: 2026/03/16 23:05:56 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
NAME                  = rush-02

# ============================== COMPILER FLAGS ============================== #
CC                    = cc
CFLAGS                = -Wall -Wextra -Werror
INCLUDES              = -Iincludes
RM                    = rm -rf

# ================================== COLORS ================================== #
GREEN                 := \033[32m
RED                   := \033[31m
YELLOW                := \033[33m
CYAN                  := \033[36m
RESET                 := \033[0m
BOLD                  := \033[1m

# =============================== SOURCE FILES =============================== #
SRC_PATH    = ./srcs
SRC         = $(SRC_PATH)/main.c \
			  $(SRC_PATH)/handler/handle_hundreds.c \
			  $(SRC_PATH)/handler/handle_magnitude.c \
			  $(SRC_PATH)/handler/handle_tens.c \
			  $(SRC_PATH)/parser/parser.c \
			  $(SRC_PATH)/printer/printer.c \
			  $(SRC_PATH)/translator/translator.c \
			  $(SRC_PATH)/utils/ft_dict_clear.c \
			  $(SRC_PATH)/utils/ft_dict_find.c \
			  $(SRC_PATH)/utils/ft_dict_new_entry.c \
			  $(SRC_PATH)/utils/ft_dict_push_back.c \
			  $(SRC_PATH)/utils/ft_isdigit.c \
			  $(SRC_PATH)/utils/ft_isspace.c \
			  $(SRC_PATH)/utils/ft_strchr.c \
			  $(SRC_PATH)/utils/ft_strcmp.c \
			  $(SRC_PATH)/utils/ft_strdup.c \
			  $(SRC_PATH)/utils/ft_strlcpy.c \
			  $(SRC_PATH)/utils/ft_strlen.c \
			  $(SRC_PATH)/utils/ft_strtrim.c \
			  $(SRC_PATH)/utils/get_clean_number.c \
			  $(SRC_PATH)/utils/get_next_line.c

OBJ_PATH    = ./objs
OBJ         = $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))

# ============================ COMPILATION RULES ============================= #
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(dir $@)
	printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(NAME)

$(NAME): $(OBJ)
	printf "$(GREEN)✔ Project objects built successfully.$(RESET)\n"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	printf "$(GREEN)$(BOLD)✔ Build complete → $(NAME)$(RESET)\n"
	
# ============================== CLEAN TARGETS =============================== #
clean:
	$(RM) $(OBJ_PATH)
	printf "$(YELLOW)• Cleaned object files.$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "$(RED)• Full clean complete.$(RESET)\n"

re: fclean all

# ============================== PHONY TARGETS =============================== #
.PHONY: all clean fclean re
