/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:54:22 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:43:47 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_move_arg(int *pointer, int argc, char **argv)
{
	int	need;
	int	cur;

	(void)argv;
	cur = argc - 1;
	need = 4;
	if (cur != need)
	{
		ft_perror_arg("pipex", cur, need);
		return (-1);
	}
	*pointer += 2;
	return (0);
}
