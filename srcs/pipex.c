/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:59:36 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/12 14:23:41 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	char	***cmds;
	int		pid;

	i = 0;
	if (ft_move_arg(&i, argc, argv) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_create_commands(argv, i, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	size = ft_command_size(argc, argv);
	pid = ft_pipe(cmds, argc, argv, envp);
	ft_strss_lfree(cmds, size);
	i = 0;
	while (i++ < size)
	{
		if (wait(NULL) == -1)
			exit(EXIT_FAILURE);
	}
	return (0);
}
