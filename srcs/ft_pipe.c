/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:45 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 19:30:42 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(char ***cmds, int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		pid;
	int		i;
	int		size;

	i = 0;
	size = ft_command_size(argc, argv);
	while (i < size)
	{
		pipe(pfd);
		pid = fork();
		if (pid == 0)
		{
			ft_redirect(i, argc, argv, pfd);
			ft_execve_path(cmds[i], envp);
		}
		ft_dup2_pipe_read(pfd);
		i++;
	}
	return (pid);
}
