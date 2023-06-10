/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:48 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:38:52 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# include "pipex.h"

int		ft_move_arg_bonus(int *pointer, int argc, char **argv);
int		ft_check_here_doc(int argc, char **argv);
int		ft_command_size_bonus(int argc, char **argv);

int		ft_pipe_bonus(char ***cmds, int argc, char **argv, char **envp);
int		ft_redirect_bonus(int i, int argc, char **argv, int pfd[2]);

void	ft_perror_arg_bonus(char *name, int cur, int need);

#endif
