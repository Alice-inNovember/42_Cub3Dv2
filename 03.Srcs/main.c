/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:35:34 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/24 12:14:02 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../02.Incs/data.h"
#include "../02.Incs/mlx.h"
#include "../02.Incs/util.h"

void	libx_loop_init(void)
{

}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	data_init(argc, argv);
	print_data();
	libx_loop_init();
	mlx_loop(data->libx->mlx);
	return (0);
}
