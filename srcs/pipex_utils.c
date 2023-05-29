/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:59:03 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 21:19:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_strsslen(char ***strss)
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
		if (printf("%d, ", n[i++]) < 0)
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
		printf("strss[%d]: ", i++);
		while ((*strss)[j])
			printf("%s, ", (*strss)[j++]);
		printf("\n");
		strss++;
	}
}

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (*strs)
	{
		printf("%s, ", strs[i++]);
		strs++;
	}
	printf("\n");
}

