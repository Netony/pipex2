/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 18:19:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	int		f_fd[2];
	char	***cmds;

	if (ft_files(argc, argv, f_fd) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_commands(argv, 2, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	size = ft_strsslen(cmds);
	if (ft_pipe(cmds, envp, f_fd, size) < 0)
		exit(EXIT_FAILURE);
	ft_strss_lfree(cmds, 0);
	i = 0;
	while (i++ < size)
	{
		if (wait(NULL) == -1)
		{
			perror("pipex");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
