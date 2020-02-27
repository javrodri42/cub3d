/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:34:47 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/26 10:45:27 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_int_char(unsigned char *start, int value)
{
    start[0] = (unsigned char)(value);
    start[1] = (unsigned char)(value >> 8);
    start[2] = (unsigned char)(value >> 16);
    start[3] = (unsigned char)(value >> 24);
}
static int  write_bmp_header(int fd, int filesize, t_params *p)
{
    int             i;
    unsigned char   bmpfileheader[54];
    i = 0;
    while (i < 54)
        bmpfileheader[i++] = (unsigned char)(0);
    bmpfileheader[0] = (unsigned char)('B');
    bmpfileheader[1] = (unsigned char)('M');
    set_int_char(bmpfileheader + 2, filesize);
    bmpfileheader[10] = (unsigned char)(54);
    bmpfileheader[14] = (unsigned char)(40);
    set_int_char(bmpfileheader + 18, p->win_width);
    set_int_char(bmpfileheader + 22, p->win_height);
    bmpfileheader[27] = (unsigned char)(1);
    bmpfileheader[28] = (unsigned char)(24);
    return (!(write(fd, bmpfileheader, 54) < 0));
}
static int  get_color(t_params *p, int x, int y)
{
    int rgb;
    int color;
    color = *(int*)(p->img_ptr + (4 * (int)p->win_width *
    ((int)p->win_height - 1 - y)) + (4 * x));
    rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
    return (rgb);
}
static int  write_bmp_data(int file, t_params *p, int pad)
{
    const unsigned char zero[3] = {0, 0, 0};
    int                 i;
    int                 j;
    int                 color;
    i = 0;
    while (i < (int)p->win_height)
    {
        j = 0;
        while (j < (int)p->win_width)
        {
            color = get_color(p, j, i);
            if (write(file, &color, 3) < 0)
                return (0);
            if (pad > 0 && write(file, &zero, pad) < 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int         save_bmp(t_params *p)
{
    int filesize;
    int file;
    int pad;
    pad = (4 - ((int)p->win_width * 3) % 4) % 4;
    filesize = 54 + (3 * ((int)p->win_width + pad)
    * (int)p->win_height);
    if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
    | O_TRUNC | O_APPEND, 777)) < 0)
        return (0);
    if (!write_bmp_header(file, filesize, p))
        return (0);
    if (!write_bmp_data(file, p, pad))
        return (0);
    close(file);
    return (1);
}
