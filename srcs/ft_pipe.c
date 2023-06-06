/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:45 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 17:13:44 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(char ***cmds, int argc, char **argv, char **envp, int size)
{
	int		pfd[2];
	int		pid;
	int		i;

	i = 0;
	while (i < size)
	{
		if (i != size - 1)
			pipe(pfd);
		pid = fork();
		if (pid == 0)
		{
			ft_redirect(i, pfd, argv[1], argv[argc - 1], size);
			ft_execve_path(cmds[i], envp);
		}
		if (i != size - 1)
			ft_dup2_pipe_read(pfd);
		i++;
	}
	return (pid);
}

