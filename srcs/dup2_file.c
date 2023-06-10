/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:36:02 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:36:03 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_dup2_infile(char *filepath, int fd)
{
	int	ffd;

	ffd = open(filepath, O_RDONLY);
	if (ffd > 0)
		dup2(ffd, fd);
	else
	{
		ft_perror_file("pipex", filepath);
		return (-1);
	}
	return (0);
}

int	ft_dup2_here_doc(void)
{
	int	ffd;

	ffd = open(".here_doc", O_RDONLY);
	dup2(ffd, 0);
	unlink(".here_doc");
	return (0);
}

int	ft_dup2_outfile(char *filepath, int fd, int pfd[2])
{
	int	ffd;

	close(pfd[0]);
	ffd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ffd > 0)
		dup2(ffd, fd);
	else
	{
		ft_perror_file("pipex", filepath);
		return (-1);
	}
	return (0);
}

int	ft_dup2_append(char *filepath, int fd, int pfd[2])
{
	int	ffd;

	close(pfd[0]);
	ffd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (ffd > 0)
		dup2(ffd, fd);
	else
	{
		ft_perror_file("pipex", filepath);
		return (-1);
	}
	return (0);
}
