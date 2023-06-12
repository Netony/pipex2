/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:01:20 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/12 15:36:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_make_pathes(char **envp);
static char	*ft_strjoin_t(char *a, char *b, char *c);
static char	*ft_grep_first(char **envp, char *grep);

int	ft_execve_path(char **command, char **envp)
{
	char	*cmd;
	char	**pathes;
	int		i;

	pathes = ft_make_pathes(envp);
	i = 0;
	if (pathes)
	{
		while (pathes[i])
		{
			cmd = ft_strjoin_t(pathes[i++], "/", command[0]);
			if (cmd)
			{
				execve(cmd, command, envp);
				free(cmd);
			}
		}
		ft_strs_lfree(pathes, i);
	}
	if (execve(command[0], command, envp) < 0)
	{
		ft_perror_command("pipex", command[0]);
		exit(127);
	}
	return (-1);
}

static char	*ft_strjoin_t(char *a, char *b, char *c)
{
	char	*temp;
	char	*join;

	temp = ft_strjoin(a, b);
	join = ft_strjoin(temp, c);
	free(temp);
	return (join);
}

static char	**ft_make_pathes(char **envp)
{
	char	*grep;
	char	**pathes;

	grep = ft_grep_first(envp, "PATH=");
	if (grep == NULL)
		return (NULL);
	pathes = ft_split(grep + ft_strlen("PATH="), ':');
	return (pathes);
}

static char	*ft_grep_first(char **envp, char *grep)
{
	int	i;

	i = 0;
	if (envp)
	{
		while (envp[i])
		{
			if (ft_strncmp(envp[i], grep, ft_strlen(grep)) == 0)
				return (envp[i]);
			i++;
		}
	}
	return (NULL);
}
