/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonusc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:09:09 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 17:24:38 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	char	***cmds;
	int		pid;

	if (ft_move_arg_bonus(&i, argc, argv) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_commands(argv, i, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	size = ft_strsslen(cmds);
	pid = ft_pipe_bonus(cmds, argc, argv, envp, size);
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
