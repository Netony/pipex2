/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:44:42 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 15:35:46 by dajeon           ###   ########.fr       */
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

int	ft_dup2_outfile(char *filepath, int fd)
{
	int	ffd;

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

int	ft_dup2_append(char *filepath, int fd)
{
	int	ffd;

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

int	ft_dup2_here_doc(char *limiter, int fd)
{
	int		ffd;
	char	*join;
	char	*line;

	join = ft_strjoin(limiter, "\n");
	ffd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (ffd)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, join, -1))
			break ;
		write(ffd, line, ft_strlen(line));
	}
	free(join);
	ffd = open(".here_doc", O_RDONLY);
	dup2(ffd, fd);
	unlink(".here_doc");
	return (0);
}
