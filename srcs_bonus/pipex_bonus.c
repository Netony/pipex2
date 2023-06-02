/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:25 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/02 21:32:25 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	char	***cmds;
	int		ret;
	int	pid;

	i = ft_move_arg(argc, argv);
	cmds = ft_commands(argv, i, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	size = ft_strsslen(cmds);
	pid = ft_pipe(cmds, argc, argv, envp, size);
	ft_strss_lfree(cmds, 0);
	if (ft_check_here_doc(argv))
		unlink(".here_doc");
	i = 0;
	while (i++ < size)
	{
		if (wait(NULL) == -1)
			exit(EXIT_FAILURE);
		if (i == size)
			waitpid(pid, &ret, 0);
	}
	return (ret);
}
