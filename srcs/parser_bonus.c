/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:44:10 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_here_doc(char *limiter);

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
	if (ft_check_here_doc(argc, argv))
		ft_here_doc(argv[2]);
	*pointer += move;
	return (0);
}

static int	ft_here_doc(char *limiter)
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
			ft_putstr_fd(line, ffd);
		else
			break ;
		free(line);
	}
	free(line);
	free(join);
	close(ffd);
	return (0);
}
