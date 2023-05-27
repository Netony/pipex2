/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/27 21:37:09 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_files(int argc, char **argv, int *i, int ffd[2])
{
	char	*join;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		ffd[0] = 0;
		join = ft_strjoin(argv[2], "\n");
		while (ft_strcmp(get_next_line(0), argv[2])) 
			;
		free(join);
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_APPNED | O_CREAT);
		*i += 2;
	}
	else
	{
		ffd[0] = open(argv[1], O_RDONLY);
		ffd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT);
		*i += 1;
	}
	if (ffd[0] > -1 && ffd[1] > -1)
		return (0);
	else
		return (-1);
}

char	***ft_commands(char **argv, int start, int end)
{
	char	***commands;
	int		i;

	i = 0;
	commands = (char ***)malloc(sizeof(char **) * (argc - 1 - i));
	while (start < end)
		commands[i++] = ft_split(argv[start++], ' ');
	commands[i] = NULL;
	return (commands);
}

char	*ft_grep(char **envp, char *grep)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], grep, ft_strlen(envp[i]))
				return (envp[i]);
		i++;	
	}
	return (NULL);
}

int		ft_strslen(char **strs)
{
	int	len;
	
	len = 0;
	while (strs[len])
		len++;
	return (len);
}

int		ft_check_path(char ***commands, char **envp)
{
	char	*temp;
	char	*temp2;
	char	**path;

	temp = ft_grep(envp, "PATH");
	path = ft_split(temp + ft_strlen("PATH="), ':');
	if (path == NULL)
		return (-1);
	while (*commands)
	{
		while (*path)
		{
			temp = ft_strjoin(*path, "/");
			temp2 = ft_strjoin(temp, **commands);
			access
		}
	}
}
