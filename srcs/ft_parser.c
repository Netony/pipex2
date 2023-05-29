/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 13:23:19 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_files(int argc, char **argv, int *count, int ffd[2])
{
	char	*join;

	if (ft_strncmp(argv[1], "here_doc", -1) == 0)
	{
		join = ft_strjoin(argv[2], "\n");
		while (ft_strncmp(get_next_line(0), join, -1))
			;
		free(join);
		ffd[0] = 0;
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		*count = 3;
	}
	else
	{
		ffd[0] = open(argv[1], O_RDONLY);
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		*count = 2;
	}
	if (ffd[0] < 0 || ffd[1] < 0)
		return (-1);
	return (0);
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
