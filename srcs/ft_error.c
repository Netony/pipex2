/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:58:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 12:08:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_malloc(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Mallocation failed", 2);
	exit(1);
}

void	ft_freel_strs(char **strs, int len)
{
	int	i;
	
	i = 0;
	while (i < len)
		free(strs[i++]);
	free(strs);
}

void	ft_perror_pipex(void)
{
	perror("pipex");
	exit(errno);
}
