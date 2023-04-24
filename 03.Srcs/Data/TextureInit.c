/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextureInit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:56:37 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/24 13:47:34 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"

t_rgb	input_rgb(char *input, char op)
{
	char	**tmp;
	char	**rgb;

	if (input[0] != op)
		err_exit("Error\nInput is not vaild!");
	tmp = ft_split(input, ' ');
	if (arr_len(tmp) != 2)
		err_exit("Error\nInput is not vaild!");
	rgb = ft_split(tmp[1], ',');
	if (arr_len(rgb) != 3)
		err_exit("Error\nInput is not vaild!");
	return (create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[0]), ft_atoi(rgb[0])));
}

void	background_init(void)
{
	t_data	*data;

	data = get_data();
	data->texture->ceiling = input_rgb(data->input->ceiling, 'C');
	data->texture->floor = input_rgb(data->input->floor, 'F');
}

void	texture_init(void)
{
	t_data	*data;

	data = get_data();
	data->texture->background = ft_smalloc(sizeof(t_image));
	data->texture->wall_n = ft_smalloc(sizeof(t_image));
	data->texture->wall_s = ft_smalloc(sizeof(t_image));
	data->texture->wall_e = ft_smalloc(sizeof(t_image));
	data->texture->wall_w = ft_smalloc(sizeof(t_image));
	data->texture->wall_n->img = wall_import(data->input->no_png);
	data->texture->wall_s->img = wall_import(data->input->so_png);
	data->texture->wall_e->img = wall_import(data->input->ea_png);
	data->texture->wall_w->img = wall_import(data->input->we_png);
	get_texture_data(data->texture->wall_n);
	get_texture_data(data->texture->wall_s);
	get_texture_data(data->texture->wall_e);
	get_texture_data(data->texture->wall_w);
	background_init();
}
