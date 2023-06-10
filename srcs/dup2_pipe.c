/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:28:53 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 20:45:09 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_dup2_pipe_write(int pfd[2])
{
	close(pfd[0]);
	dup2(pfd[1], 1);
	close(pfd[1]);
	return (0);
}

int	ft_dup2_pipe_read(int pfd[2])
{
	close(pfd[1]);
	dup2(pfd[0], 0);
	close(pfd[0]);
	return (0);
}
