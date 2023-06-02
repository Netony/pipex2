/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:10 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/02 21:34:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_move_arg(int argc, char **argv)
{
	int	start;
	int	num_cmd;

	start = 2;
	if (ft_check_here_doc(argv))
		start++;
	num_cmd = (argc - 1) - start;
	if (num_cmd < 2)
	{
		ft_perror_nevar("pipex", argc - 1, ft_check_here_doc(argv));
		exit(EXIT_FAILURE);
	}
	return (start);
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


int	ft_check_here_doc(char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", -1) == 0)
		return (1);
	else
		return (0);
}
