/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/18 22:01:09 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	int	i;
	int	argc;
	int	fds[2];

	// open("./infile", O_RDONLY);
	argc = 5;
	i = 0;
	while (i++ < argc - 1)
	{
		pipe(fds);
		if (fork() == 0)
		{
			close(fds[0]);
			dup2(fds[1], 1);
			// execve();
		}
		if (i != argc - 1)
		{
			close(fds[1]);
			dup2(fds[0], 0);
		}
		else
		{
			dup2(fds[0], 1);
			break ;
		}
	}
	
	
}
