/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:22 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 16:30:28 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_move_arg(int *pointer, int argc, char **argv)
{
	int	need;
	int	cur;

	(void)argv;
	cur = argc - 1;
	need = 4;
	if (cur != need)
	{
		ft_perror_arg("pipex", cur, need);
		return (-1);
	}
	*pointer += 2;
	return (0);
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
