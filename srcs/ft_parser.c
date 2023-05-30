/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 18:06:23 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_files(int argc, char **argv, int ffd[2])
{
	ffd[0] = open(argv[1], O_RDONLY);
	ffd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (!(ffd[0] < 0) && !(ffd[1] < 0) && argc == 5)
		return (0);
	else if (argc != 5)
		ft_perror_var("pipex", argc - 1);
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
