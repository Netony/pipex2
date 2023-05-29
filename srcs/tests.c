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

