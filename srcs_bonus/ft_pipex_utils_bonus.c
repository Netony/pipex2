/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:18 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 17:59:19 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strsslen(char ***strss)
{
	int	len;

	len = 0;
	while (strss[len])
		len++;
	return (len);
}

int	ft_print_ints(int *n, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_printf("%d, ", n[i++]) < 0)
			return (0);
	}
	return (1);
}

void	ft_print_strss(char ***strss)
{
	int	i;
	int	j;

	i = 0;
	while (*strss)
	{
		j = 0;
		ft_printf("strss[%d]: ", i++);
		while ((*strss)[j])
			ft_printf("%s, ", (*strss)[j++]);
		ft_printf("\n");
		strss++;
	}
}

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (*strs)
	{
		ft_printf("%s, ", strs[i++]);
		strs++;
	}
	ft_printf("\n");
}
