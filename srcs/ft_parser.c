/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 21:29:29 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_files(int argc, char **argv, int *count, int ffd[2])
{
	if (ft_strncmp(argv[1], "here_doc", -1) == 0)
	{
		ffd[0] = ft_here_doc(argv);
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		*count = 3;
	}
	else
	{
		ffd[0] = open(argv[1], O_RDONLY);
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		*count = 2;
	}
	if (ffd[0] >= 0 && ffd[1] >= 0)
		return (0);
	if (ffd[0] < 0)
		perror(argv[1]);
	if (ffd[1] < 0)
		perror(argv[argc - 1]);
	return (-1);
}

char	***ft_commands(char **argv, int start, int end)
{
	char	***commands;
	int		i;

	i = 0;
	commands = (char ***)malloc(sizeof(char **) * (end - start + 1));
	while (start < end)
		commands[i++] = ft_split(argv[start++], ' ');
	commands[i] = NULL;
	return (commands);
}

int	ft_here_doc(char **argv)
{
	char	*join;
	char	*buf;
	int		fd;

	join = ft_strjoin(argv[2], "\n");
	fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		buf = get_next_line(0);
		if (ft_strncmp(buf, join, -1))
		{
			ft_putstr_fd(buf, fd);
			printf("%s", buf);
		}
		else
			break ;
	}
	close(fd);
	fd = open(".here_doc", O_RDONLY);
	return (fd);
}
