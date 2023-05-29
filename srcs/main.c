/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 13:24:46 by dajeon           ###   ########.fr       */
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
	dup2(f_fd[0], 0);
	size = ft_strsslen(cmds);
	printf("ffd[0]: %d\n", f_fd[0]);
	printf("ffd[1]: %d\n", f_fd[1]);
	while (i < size)
	{
		pipe(p_fd);
		if (fork() == 0)
		{
			close(p_fd[0]);
			if (i != size - 1)
				dup2(p_fd[1], 1);
			else
				dup2(f_fd[1], 1);
			ft_execve_path(cmds[i], envp);
		}
		close(p_fd[1]);
		dup2(p_fd[0], 0);
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
