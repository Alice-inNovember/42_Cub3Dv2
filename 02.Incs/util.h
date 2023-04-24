/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:48:17 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/24 13:19:08 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>
# include "data.h"

//Util.c
void	err_exit(char *str);
void	*ft_smalloc(size_t size);
void	*ft_scalloc(size_t count, size_t size);
int		arr_len(char **arr);

//DebugPrint.c
void	test_input(t_data *data);
void	print_map(void);
void	print_data(void);

//MapUtil.c
void	get_player_data(double *x, double *y, char *face);

//TextureUtil.c
void	*wall_import(char *path);
void	get_texture_data(t_image *img);

//RGBUtil.c
t_rgb	create_trgb(int t, int r, int g, int b);
int		get_t(t_rgb trgb);
int		get_r(t_rgb trgb);
int		get_g(t_rgb trgb);
int		get_b(t_rgb trgb);

#endif