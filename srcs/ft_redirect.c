/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:02:57 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 20:21:53 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_redirect(int i, int argc, char **argv, int pfd[2])
{
	int	size;

	size = ft_command_size(argc, argv);
	if (i == 0)
	{
		if (ft_dup2_infile(argv[1], 0) < 0)
			exit(EXIT_FAILURE);
	}
	if (i == size - 1)
		ft_dup2_outfile(argv[argc - 1], 1, pfd);
	else
		ft_dup2_pipe_write(pfd);
	return (0);
}
