/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:37:13 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:37:14 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_strs_lfree(char **strs, int len)
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

void	ft_strss_lfree(char ***strss, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
			ft_strs_lfree(strss[i++], 0);
	}
	else
	{
		while (strss[i])
			ft_strs_lfree(strss[i++], 0);
	}
	free(strss);
}
