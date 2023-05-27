/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/27 21:11:52 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "lib.h"

int		ft_files(int argc, char **argv, int *i, int ffd[2]);
int		ft_print_ints(int *n, size_t size);
char	***ft_commands(char **argv, int start, int end);
void	ft_print_strss(char ***strss);

int	main(int argc, char **argv)
{
	int		ffd[2];
	char	***commands;
	int		i;

	i = 0;
	if (argc > 4)
		printf("%d\n", ft_files(argc, argv, &i, ffd));
	commands = ft_commands(argv, i, argc);
	ft_print_strss(commands);
	return (0);
}

int	ft_files(int argc, char **argv, int *count, int ffd[2])
{
	if (ft_strncmp(argv[1], "here_doc", -1) == 0)
	{
		while (ft_strncmp(get_next_line(0), ft_strjoin(argv[2], "\n"), -1))
			;
		ffd[0] = 0;
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		*count = 3;
	}
	else
	{
		ffd[0] = open(argv[1], O_RDONLY);
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		*count = 2;
	}
	return (1);
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

char	***ft_commands(char **argv, int start, int end)
{
	char	***commands;
	int		i;

	i = 0;
	commands = (char ***)malloc(sizeof(char **) * (end - start + 1));

	while (start < end)
	{
		commands[i] = ft_split(argv[start++], ' ');
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
