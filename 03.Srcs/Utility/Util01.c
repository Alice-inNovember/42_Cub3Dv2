/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:29:42 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/17 17:33:30 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../02.Incs/libft.h"

void	err_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	*ft_smalloc(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (!temp)
		err_exit("Error\n : malloc err");
	return (temp);
}

void	*ft_scalloc(size_t count, size_t size)
{
	unsigned char	*returnptr;
	size_t			test;

	test = count * size;
	if (size != 0 && (test / size != count))
		return ((void *)0);
	returnptr = (unsigned char *)malloc(count * size);
	if (!returnptr)
		err_exit("Error\n : malloc err");
	ft_memset((void *)returnptr, 0, count * size);
	return ((void *)returnptr);
}
