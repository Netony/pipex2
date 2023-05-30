/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:25 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 18:45:29 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	int		f_fd[2];
	char	***cmds;

	if (ft_files(argc, argv, &i, f_fd) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_commands(argv, i, argc - 1);
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
			exit(EXIT_FAILURE);
	}
	return (0);
}
