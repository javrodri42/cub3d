# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 11:51:30 by javrodri          #+#    #+#              #
#    Updated: 2020/02/07 11:03:55 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

SRCS 		=  	main.c \
				utils.c 	\
				get_next_line.c \
				map_reader.c \
				ft_atoi.c \
				ft_itoa.c \
				ft_putstr.c \
				utils_2.c \
				get_next_line_utils.c \
				map_position.c \
				textures.c \
				draw.c \
				imput_keys.c \
				ray_casting.c \
				parser.c 

all: $(NAME)

$(NAME) : $(SRCS) cub3d.h
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit
1:			
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map1.cub"

2:			
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map2.cub"

3:			
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map3.cub"

4:			
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map4"

5:			
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map5"
			 
6:			
			-@clear
			 @gcc $(SRCS) -lmlx -framework OpenGL -framework AppKit && ./a.out "maps/map0"
			
clean:
			-@$(RM) $(OBJS) 

fclean: clean
			-@$(RM) $(NAME)

re: 		fclean all