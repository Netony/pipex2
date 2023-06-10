/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:13:13 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 19:34:15 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_command_size_bonus(int argc, char **argv)
{
	return (argc - (3 + ft_check_here_doc(argc, argv)));
}

int	ft_check_here_doc(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", -1) == 0)
		return (1);
	else
		return (0);
}
