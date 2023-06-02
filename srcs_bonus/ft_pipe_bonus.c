/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:15 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/02 22:03:03 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_pipe_redirect(int p_fd[2]);
static void	ft_infile_redirect(char **argv, int p_fd[2]);
static void	ft_outfile_redirect(int argc, char **argv, int p_fd[2]);
static int	ft_here_doc(char **argv);

int	ft_pipe(char ***cmds, int argc, char **argv, char **envp, int size)
{
	int	p_fd[2];
	int	j;
	int	pid;

	j = 0;
	while (j < size)
	{
		pipe(p_fd);
		pid = fork();
		if (pid == 0)
		{
			if (j == 0)
				ft_infile_redirect(argv, p_fd);
			else if (j == size - 1)
				ft_outfile_redirect(argc, argv, p_fd);
			else
				ft_pipe_redirect(p_fd);
			if (ft_execve_path(cmds[j], envp) < 0)
				exit(EXIT_FAILURE);	
		}
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		j++;
	}
	return (pid);
}

static void	ft_infile_redirect(char **argv, int p_fd[2])
{
	int 	in_fd;

	if (ft_check_here_doc(argv))
		in_fd = ft_here_doc(argv);
	else
		in_fd = open(argv[1], O_RDONLY);
	close(p_fd[0]);
	dup2(in_fd, 0);
	if (in_fd < 0)
	{
		unlink(argv[1]);
		ft_perror("pipex", argv[1]);
	}
	dup2(p_fd[1], 1);
}

static void	ft_outfile_redirect(int argc, char **argv, int p_fd[2])
{
	int	out_fd;

	if (ft_check_here_doc(argv))
		out_fd = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		out_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	close(p_fd[0]);
	dup2(out_fd, 1);
}

static void	ft_pipe_redirect(int p_fd[2])
{
	close(p_fd[0]);
	dup2(p_fd[1], 1);
}

static int	ft_here_doc(char **argv)
{
	char	*join;
	char	*buf;
	int		fd;

	join = ft_strjoin(argv[2], "\n");
	fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (fd)
	{
		buf = get_next_line(0);
		if (ft_strncmp(buf, join, -1))
			ft_putstr_fd(buf, fd);
		else
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	free(join);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(".here_doc", O_RDONLY);
	return (fd);
}
