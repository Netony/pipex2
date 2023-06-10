/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:59:52 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:38:30 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "lib.h"

int		ft_move_arg(int *pointer, int argc, char **argv);
char	***ft_create_commands(char **argv, int start, int end);
int		ft_pipe(char ***cmds, int argc, char **argv, char **envp);
int		ft_redirect(int i, int argc, char **argv, int pfd[2]);
int		ft_execve_path(char **command, char **envp);

void	ft_strs_lfree(char **strs, int len);
void	ft_strss_lfree(char ***strss, int len);

void	ft_perror_malloc(char *name);
void	ft_perror_file(char *name, char *filename);
void	ft_perror_command(char *name, char *command);
void	ft_perror_arg(char *name, int cur, int need);
void	ft_perror(char *name1, char *name2);

int		ft_command_size(int argc, char **argv);

int		ft_dup2_infile(char *filepath, int fd);
int		ft_dup2_here_doc(void);
int		ft_dup2_outfile(char *filepath, int fd, int pfd[2]);
int		ft_dup2_append(char *filepath, int fd, int pfd[2]);

int		ft_dup2_pipe_write(int pfd[2]);
int		ft_dup2_pipe_read(int pfd[2]);

#endif
