/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:37:02 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 21:37:03 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror_malloc(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Mallocation failed", 2);
}

void	ft_perror(char *name1, char *name2)
{
	ft_putstr_fd(name1, 2);
	ft_putstr_fd(": ", 2);
	perror(name2);
}

void	ft_perror_arg(char *name, int cur, int need)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Need exactly ", 2);
	ft_putnbr_fd(need, 2);
	ft_putstr_fd(" variable. You: ", 2);
	ft_putnbr_fd(cur, 2);
	ft_putendl_fd("", 2);
}

void	ft_perror_file(char *name, char *filename)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": No such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
}

void	ft_perror_command(char *name, char *command)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": command not found: ", 2);
	ft_putendl_fd(command, 2);
}
