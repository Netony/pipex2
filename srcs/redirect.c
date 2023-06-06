/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:27:24 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 17:14:04 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_redirect(int i, int pfd[2], char *infile, char *outfile, int size)
{
	if (i == 0)
	{
		if (ft_dup2_infile(infile, 0) < 0)
			exit(EXIT_FAILURE);
		ft_dup2_pipe_write(pfd);
	}
	else if (i == size - 1)
		ft_dup2_outfile(outfile, 1);
	else
		ft_dup2_pipe_write(pfd);
	return (0);
}
