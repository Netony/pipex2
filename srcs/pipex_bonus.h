/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:48 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 17:23:47 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# include "pipex.h"

int		ft_move_arg_bonus(int *pointer, int argc, char **argv);
int		ft_check_here_doc(int argc, char **argv);
void	ft_perror_arg_bonus(char *name, int cur, int need);
int		ft_pipe_bonus(char ***cmds, int argc, char **argv, char **envp, int size);

#endif
