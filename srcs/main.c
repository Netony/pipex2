/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 21:29:28 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	int		f_fd[2];
	int		p_fd[2];
	char	***cmds;
	int		size;

	if (ft_files(argc, argv, &i, f_fd) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_commands(argv, i, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	dup2(f_fd[0], 0);
	j = 0;
	size = ft_strsslen(cmds);
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
			ft_execve_path(cmds[j], envp);
		}
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		j++;
	}
	j = 0;
	while (j++ < size)
	{
		if (wait(NULL) == -1)
			exit(EXIT_FAILURE);
	}
	return (0);
}

