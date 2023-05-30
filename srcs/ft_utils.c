/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:14:27 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 17:15:27 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("strs[%d]: %s\n", i, strs[i]);
		i++;
	}
}

void	ft_print_strss(char ***strss)
{
	int	i;
	int	j;

	i = 0;
	while (strss[i])
	{
		j = 0;
		while (strss[i][j])
		{
			printf("cmds[%d][%d]: %s\n", i, j, strss[i][j]);
			j++;
		}
		i++;
	}
	printf("SUCCESS\n");
}

int	ft_strsslen(char ***strss)
{
	int	len;

	len = 0;
	while (strss[len])
		len++;
	return (len);
}
