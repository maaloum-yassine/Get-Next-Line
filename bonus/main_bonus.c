/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 03:13:02 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/08 07:41:25 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"
#include <fcntl.h>


#define ERR_OPEN "ERREUR OPEN FILE\n"
#define ERR_CLOSE1 "ERREUR CLOSE FILE 1\n"
#define ERR_CLOSE2 "ERREUR CLOSE FILE 2\n"
#define ERR_CLOSE3 "ERREUR CLOSE FILE 3\n"

int main (void)
{
	char	*line;
	int		fd[3];
	int		check;
	int		i;

	check = 0;
	i = 0;
	fd[0] =  open ("file_test/file1.txt", O_RDONLY);
	fd[1] =  open ("file_test/file2.txt", O_RDONLY);
	fd[2] =  open ("file_test/file3.txt", O_RDONLY);

	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1)
		write(2, ERR_OPEN, ft_strlen(ERR_OPEN));
	else
	{
		while (1)
		{
			if (++i > 2)
				i = 0;
			line = get_next_line(fd[i]);
			if (line != NULL)
			{
				check = 0;
				write(1, line, ft_strlen(line));
				free (line);
			}
			else
				++check;
			if (check > 2)
				break ;
		}
	}
	check = 0;
	if (fd[0] != -1)
	{
		if (close(fd[0]) == -1)
		{
			write(2, ERR_CLOSE1, ft_strlen(ERR_CLOSE1));
			check = 1;
		}
	}
	if (fd[1] != -1)
	{
		if (close(fd[1]) == -1)
		{
			write(2, ERR_CLOSE2, ft_strlen(ERR_CLOSE2));
			check = 1;
		}
	}
	if (fd[2] != -1)
	{
		if (close(fd[2]) == -1)
		{
			write(2, ERR_CLOSE3, ft_strlen(ERR_CLOSE3));
			check = 1;
		}
	}
	return (check);
}
