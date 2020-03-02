# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 11:51:30 by javrodri          #+#    #+#              #
#    Updated: 2020/03/02 19:03:01 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

SRCS 		=  	main.c \
				utils.c 	\
				utils_2.c \
				utils_3.c \
				get_next_line.c \
				ft_atoi.c \
				ft_itoa.c \
				ft_putstr.c \
				get_next_line_utils.c \
				map_position.c \
				textures.c \
				draw.c \
				imput_keys.c \
				ray_casting.c \
				parser.c  \
				parser2.c  \
				parser3.c  \
				save_bmp.c \
				ray_casting_bmp.c \
				sprite.c

all: $(NAME)

$(NAME) : $(SRCS) cub3d.h
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit
1:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map1.cub"
			 @echo "\033[0m"

2:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map2.cub"
			 @echo "\033[0m"

3:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map2.cub --save"
			 @echo "\033[0m"
4:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map4"
			 @echo "\033[0m"
5:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map5"
			 @echo "\033[0m"
			 
6:			
			-@clear
			 @echo "\n\033[0;33mCompiling...\n"
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map0"
			 @echo "\033[0m"

debug:	 	
			 @gcc $(SRCS) -g -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map2.cub"
			
clean:
			-@$(RM) $(OBJS) 

fclean: clean
			-@$(RM) $(NAME)

re: 		fclean all