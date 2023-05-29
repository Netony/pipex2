/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 13:06:32 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_strsslen(char ***strss);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		f_fd[2];
	int		p_fd[2];
	char	***cmds;
	int		size;

	if (ft_files(argc, argv, &i, f_fd) < 0)
		perror("pipex");
	cmds = ft_commands(argv, i, argc - 1);
	i = 0;
	size = ft_strsslen(cmds);
	while (i < size)
	{
		pipe(p_fd);
		if (fork() == 0)
		{
			if (i != size - 1)
			{
				close(p_fd[0]);
				dup2(p_fd[1], 1);
				ft_execve_path(cmds[i], envp);
			}
		}
		else
		{
			if (i == size - 1)
			{
				close(p_fd[1]);
				dup2(p_fd[0], 1);
			}
			else
			{
				close(p_fd[1]);
				dup2(p_fd[0], 0);
			}
		}
		i++;
	}
}

int		ft_strsslen(char ***strss)
{
	int	len;

	len = 0;
	while (strss[len])
		len++;
	return (len);
}
