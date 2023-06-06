/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:59:36 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 16:40:29 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		size;
	char	***cmds;
	int		ret;
	int		pid;

	if (ft_move_arg(&i, argc, argv) < 0)
		exit(EXIT_FAILURE);
	cmds = ft_commands(argv, i, argc - 1);
	if (cmds == NULL)
		exit(EXIT_FAILURE);
	pid = ft_pipe(cmds, argc, argv, envp, size);
	ft_strss_lfree(cmds, 0);
	i = 0;
	size = ft_strsslen(cmds);
	waitpid(pid, &ret, 0);
	while (i++ < size - 1)
	{
		if (wait(NULL) == -1)
			exit(EXIT_FAILURE);
	}
	if (WIFEXITED(ret))
		ret = WEXITSTATUS(ret);
	else
		ret = 42;
	return (ret);
}
