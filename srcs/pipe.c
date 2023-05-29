int	pipe(void)
{
	argc = 5;
	i = 0;
	while (i++ < argc - 1)
	{
		pipe(pfd);
		if (fork() == 0)
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
			// execve();
		}
		if (i != argc - 1)
		{
			close(pfd[1]);
			dup2(pfd[0], 0);
		}
		else
		{
			dup2(pfd[0], 1);
		}
	}
}
