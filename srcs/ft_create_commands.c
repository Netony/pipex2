/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:20:13 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 19:20:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***ft_create_commands(char **argv, int start, int end)
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
