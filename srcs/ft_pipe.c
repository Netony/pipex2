/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:57:45 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 18:08:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(char ***cmds, char **envp, int f_fd[2], int size)
{
	int		p_fd[2];
	int		j;

	dup2(f_fd[0], 0);
	j = 0;
	while (j < size)
	{
		pipe(p_fd);
		if (fork() == 0)
		{
			close(p_fd[0]);
			if (j == size - 1)
				dup2(f_fd[1], 1);
			else
				dup2(p_fd[1], 1);
			if (ft_execve_path(cmds[j], envp) < 0)
				return (-1);
		}
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		j++;
	}
	return (j);
}
