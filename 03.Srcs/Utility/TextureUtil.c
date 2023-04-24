/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextureUtil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:40:36 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/24 13:05:11 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"
#include "../../02.Incs/mlx.h"

void	*wall_import(char *path)
{
	t_data	*data;
	void	*img;
	int		w;
	int		h;

	data = get_data();
	img = mlx_xpm_file_to_image(data->libx->mlx, path, &w, &h);
	if (w != 64 || h != 64)
		err_exit("Error\nImg file size must be 64 * 64 !");
	return (img);
}

void	get_texture_data(t_image	*img)
{
	img->addr = mlx_get_data_addr(\
	img->img, \
	&img->bits_per_pixel, \
	&img->line_length, \
	&img->endian);
}
