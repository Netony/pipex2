/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:36:23 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:22:20 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_redirect_here_doc(int i, int argc, char **argv, int pfd[2]);
static int	ft_redirect_file(int i, int argc, char **argv, int pfd[2]);

int	ft_redirect_bonus(int i, int argc, char **argv, int pfd[2])
{
	int	size;

	size = ft_command_size_bonus(argc, argv);
	if (ft_check_here_doc(argc, argv) == 0)
	{
		if (ft_redirect_file(i, argc, argv, pfd) < 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (ft_redirect_here_doc(i, argc, argv, pfd) < 0)
			exit(EXIT_FAILURE);
	}
	return (0);
}

static int	ft_redirect_file(int i, int argc, char **argv, int pfd[2])
{
	int	size;

	size = ft_command_size_bonus(argc, argv);
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

static int	ft_redirect_here_doc(int i, int argc, char **argv, int pfd[2])
{
	int	size;

	size = ft_command_size_bonus(argc, argv);
	if (i == 0)
	{
		if (ft_dup2_here_doc() < 0)
			exit(EXIT_FAILURE);
	}
	if (i == size - 1)
		ft_dup2_append(argv[argc - 1], 1, pfd);
	else
		ft_dup2_pipe_write(pfd);
	return (0);
}
