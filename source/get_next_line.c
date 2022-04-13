/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:05:25 by gmyriah           #+#    #+#             */
/*   Updated: 2022/04/13 13:05:27 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_next_line_fd(int fd, char **line)
{
	int		result;
	int		i;
	char	*buffer;

	result = 0;
	i = 0;
	buffer = malloc(100000);
	if (!buffer)
		return (0);
	*line = buffer;
	result = read(fd, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\n')
	{
		i++;
		result = read(fd, &buffer[i], 1);
	}
	buffer[i] = '\0';
	return (result);
}
