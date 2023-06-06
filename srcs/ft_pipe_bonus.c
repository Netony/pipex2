/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:03:52 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 16:29:07 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

static int	ft_redirect_bonus(int i, int pfd[2], char *limiter, char *outfile);

int	ft_pipe_bonus(char ***cmds, int argc, char **argv, char **envp)
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
			if (ft_check_here_doc(argc, argv) == 0)
			{
				if (ft_redirect(i, pfd, argv[1], argv[argc - 1], size) < 0)
					exit(EXIT_FAILURE);
			}
			else
				ft_redirect_bonus(i, pfd, argv[1], argv[argc - 1]);
			ft_execve_path(cmds[i], envp);
		}
		if (i != size - 1)
			ft_dup2_pipe_read(pfd);
		i++;
	}
	return (pid);
}

static int	ft_redirect_bonus(int i, int pfd[2], char *limiter, char *outfile)
{
	if (i == 0)
	{
		ft_dup2_here_doc(limiter, 0);
		ft_dup2_pipe_write(pfd);
	}
	else if (i == size - 1)
		ft_dup2_append(argv[argc - 1], 1);
	else
		ft_dup2_pipe_write(pfd);
	return (0);
}
