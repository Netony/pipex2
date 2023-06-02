/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:58:48 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/02 21:30:46 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "lib_bonus.h"

int		ft_move_arg(int argc, char **argv);
char	***ft_commands(char **argv, int start, int end);
int		ft_check_here_doc(char **argv);

int		ft_pipe(char ***cmds, int argc, char **argv, char **envp, int size);
int		ft_execve_path(char **command, char **envp);

void	ft_strs_lfree(char **strs, int len);
void	ft_strss_lfree(char ***strss, int len);
void	ft_perror_malloc(char *name);
void	ft_perror_nevar(char *name, int nbr, int here_doc);
void	ft_perror(char *name1, char *name2);

void	ft_print_strss(char ***strss);
void	ft_print_strs(char **strs);
int		ft_print_ints(int *n, size_t size);

int		ft_strs_size(char **strs);
int		ft_strsslen(char ***strss);
#endif
