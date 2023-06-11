/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:09:09 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/11 21:08:56 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	char	***cmds;
	int		pid;

	i = 0;
	if (ft_move_arg_bonus(&i, argc, argv) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_create_commands(argv, i, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	size = ft_command_size_bonus(argc, argv);
	pid = ft_pipe_bonus(cmds, argc, argv, envp);
	ft_strss_lfree(cmds, 0);
	if (ft_check_here_doc(argc, argv))
		unlink(".here_doc");
	i = 0;
	while (i++ < size)
	{
		if (wait(NULL) == -1)
			exit(EXIT_FAILURE);
	}
	return (0);
}
