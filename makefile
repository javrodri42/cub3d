# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 11:51:30 by javrodri          #+#    #+#              #
#    Updated: 2020/03/07 12:31:28 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS 		=  	src/cub3d.c \
				src/utils.c 	\
				src/utils_2.c \
				src/utils_3.c \
				src/utils_4.c \
				src/get_next_line.c \
				src/ft_atoi.c \
				src/ft_itoa.c \
				src/ft_putstr.c \
				src/get_next_line_utils.c \
				src/map_position.c \
				src/textures.c \
				src/draw.c \
				src/imput_keys.c \
				src/ray_casting.c \
				src/parser.c  \
				src/parser2.c  \
				src/parser3.c  \
				src/save_bmp.c \
				src/ray_casting_bmp.c \
				src/sprite.c

all: $(NAME)

$(NAME) : $(SRCS) src/cub3d.h
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
1:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map1.cub"
			 @echo "\033[0m"

2:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map2.cub"
			 @echo "\033[0m"

3:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map2.cub" --save
			 @echo "\033[0m"
4:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map4.cub"
			 @echo "\033[0m"
5:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map5.cub"
			 @echo "\033[0m"
			 
6:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map0"
			 @echo "\033[0m"

debug:	 	
			 @gcc $(SRCS) -g -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d "maps/map2.cub"
			
clean:
			-@$(RM) $(OBJS) 

fclean: clean
			-@$(RM) $(NAME)

re: 		fclean all