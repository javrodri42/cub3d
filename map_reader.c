/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:13:35 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/25 11:47:56 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_reader_check(t_params *p, int fd)
{
	char *line;

	get_next_line(fd, &line);
	if (line[0] != 'R' || line[1] != ' ')
		close_failure("Error\nNo resolution defined\n");
	if (!(p->win_width = ft_atoi(line + 2)))
		close_failure("Error\nNo resolution defined\n");
	line += ft_strlen(ft_itoa(p->win_width)) + 3;
	if (!(p->win_height = ft_atoi(line)))
		close_failure("Error\nNo resolution defined\n");
	get_next_line(fd, &line);
	if (ft_strlen(line) > 0)
		close_failure("Error\nNo correct file format\n");
}

static char ft_delete_spaces(char *text)
{
   char  blank[1000];
   int c = 0, d = 0;
     
   while (text[c] != '\0') 
   {
      if (text[c] == ' ') 
	  {
         int temp = c + 1;
         if (text[temp] != '\0') 
		 {
            while (text[temp] == ' ' && text[temp] != '\0') 
			{
               if (text[temp] == ' ') 
			   {
                  c++;
               }  
               temp++;
            }
         }
      }
      blank[d] = text[c];
      c++;
      d++;
   }
 
   blank[d] = '\0';
   
   return(*blank);
}


/*
char	ft_delete_spaces(char *line)
{
	char	*aux;
	int		i;

	i = 0;
	//line = (char *)line;
	while(line)
	{
		if (line[i] == " ")
			i++;
		else
		{
			aux[i] = line[i];
			i++;
		}
	}
	return (*aux);
}*/

void		map_reader(t_params *p, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(p->map_file, O_RDONLY)) == -1)
	    close_failure("Error\nCan not open file\n");
	map_reader_check(p, fd);
	while (get_next_line(fd, &line))
	{
		i = -1;
		//line = ft_delete_spaces(line);
		if (!p->map_width)
			p->map_width = ft_strlen(line);
		while (line[++i])
			p->map[p->map_height][i] = line[i] - '0';
		p->map_height++;
	}
	i = -1;
	while (++i < p->map_width)
		p->map[p->map_height][i] = line[i] - '0';
	p->map_height++;
	map_position(p);
	//map_error_check(p);
	free(line);
}



