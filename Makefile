# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 14:39:00 by prichard          #+#    #+#              #
#    Updated: 2016/06/07 18:29:08 by prichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src
SRC_NAME = 	main.c\
			mandelbrot.c\
			julia.c\
			glynn.c\
			keyhooks.c\
			move.c\
			init_fractal.c\
			drawing.c\
			fract_compl.c\
			modify_iter_max.c\
			zoom.c\
			mouse_hook.c\
			menu.c\
			image.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

PATH_INC = include
PATH_LIBFT = libft/
LIBFT = libft/libft.a
PATH_MINILIBX = minilibx/
MINILIBX = minilibx/libmlx.a -lmlx -framework OpenGL -framework AppKit
#MINILIBX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I,$(PATH_INC) $(PATH_LIBFT) $(PATH_MINILIBX))

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
MAGENTA = \x1b[35;01m

all: maklibft makminilibx $(NAME) end

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MINILIBX) $(OBJ) -o $(NAME) 
	@echo "$(GREEN)CC >>$(NO_COLOR) $(CFLAGS) libft minilibx $(GREEN)>>$(NO_COLOR) \
	$(OBJ_PATH) $(GREEN)>> $(NAME)$(NO_COLOR)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(GREEN)CC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $< $(MAGENTA)>>$(NO_COLOR) $@"

maklibft:
	@make -C libft
	@echo "$(RED)-------------------------------------$(NO_COLOR)"

makminilibx:
	@make -C minilibx
	@echo "$(RED)-------------------------------------$(NO_COLOR)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)RM >>$(NO_COLOR) $(OBJ_PATH)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)RM >>$(NO_COLOR) $(NAME)"

gfclean: fclean
	make fclean -C libft
	make clean -C minilibx

re: fclean all

end:
	@echo "$(RED)-------------------------------------$(NO_COLOR)"

norme:
	norminette $(SRC)
	norminette $(PATH_INC)/fdf.h

.PHONY: all lib clean fclean gfclean re norme makelib title end
