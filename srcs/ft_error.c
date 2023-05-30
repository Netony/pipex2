/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:58:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 17:18:59 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror_malloc(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Mallocation failed", 2);
}

void	ft_perror_nevar(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Not enough variable. at least 4(here_doc: 5)", 2);
}

void	ft_freel_strs(char **strs, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
			free(strs[i++]);
	}
	else
	{
		while (strs[i])
			free(strs[i++]);
	}
	free(strs);
}

void	ft_freel_strss(char ***strss, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
			ft_freel_strs(strss[i++], 0);
	}
	else
	{
		while (strss[i])
			ft_freel_strs(strss[i++], 0);
	}
	free(strss);
}

void	ft_perror(char *name1, char *name2)
{
	ft_putstr_fd(name1, 2);
	perror(name2);
}
