/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/06 16:05:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

int	ft_move_arg_bonus(int *pointer, int argc, char **argv)
{
	int	need;
	int	cur;
	int	move;

	cur = argc - 1;
	need = 4 + ft_check_here_doc(argc, argv);
	if (cur < need)
	{
		ft_perror_arg("pipex", cur, need);
		return (-1);
	}
	move = 2 + ft_check_here_doc(argc, argv);
	*pointer += move;
	return (0);
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
