/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibxInit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:12:43 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/17 18:13:36 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"

void	libx_init(void)
{
	t_libx	*libx;

	libx = get_data()->libx;
	libx->mlx = mlx_init();
	libx->title = ft_strdup("Cube 3D");
	libx->win = mlx_new_window(libx->mlx, WIDTH, HIGHT, libx->title);
}
