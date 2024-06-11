/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 03:13:02 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/08 07:34:57 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <fcntl.h>


#define ERR_OPEN "ERREUR OPEN FILE\n"
#define ERR_CLOSE "ERREUR CLOSE FILE\n"

int main (void)
{
	char *line;
	int fd = open ("file_test/test.txt", O_RDONLY);

	if (fd == -1)
	{
		write(2, ERR_OPEN, ft_strlen(ERR_OPEN));
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		write(1, line, ft_strlen(line));
		free (line);
	}
	if (close(fd) == -1)
	{
		write(2, ERR_CLOSE, ft_strlen(ERR_CLOSE));
		return (1);
	}
	// system("LEAKS getnextline");
	return  (0);
}
