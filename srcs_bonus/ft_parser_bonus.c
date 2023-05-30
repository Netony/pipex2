/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:10 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 18:35:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_here_doc(char **argv);

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
	if (!(ffd[0] < 0) && !(ffd[1] < 0) && !(argc - 1 - *count < 2))
		return (0);
	else if (argc - 1 - *count < 2)
		ft_perror_nevar("pipex", 2 - argc - 1 - *count, ft_strncmp(argv[1], "here_doc", -1) == 0);
	else if (ffd[0] < 0)
		ft_perror("pipex", argv[1]);
	else if (ffd[1] < 0)
		ft_perror("pipex", argv[argc - 1]);
	return (-1);
}

char	***ft_commands(char **argv, int start, int end)
{
	char	***commands;
	int		i;

	i = 0;
	commands = (char ***)malloc(sizeof(char **) * (end - start + 1));
	if (commands == NULL)
	{
		ft_perror_malloc("pipex");
		return (NULL);
	}		
	while (start < end)
	{
		commands[i] = ft_split(argv[start++], ' ');
		if (commands[i] == NULL)
		{
			ft_perror_malloc("pipex");
			ft_strss_lfree(commands, i);
			return (NULL);
		}
		i++;
	}
	commands[i] = NULL;
	return (commands);
}

static int	ft_here_doc(char **argv)
{
	char	*join;
	char	*buf;
	int		fd;

	join = ft_strjoin(argv[2], "\n");
	fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (fd)
	{
		buf = get_next_line(0);
		if (ft_strncmp(buf, join, -1))
			ft_putstr_fd(buf, fd);
		else
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	free(join);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(".here_doc", O_RDONLY);
	unlink(".here_doc");
	return (fd);
}
