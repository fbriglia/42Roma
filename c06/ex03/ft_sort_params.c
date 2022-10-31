int	ft_strcmp (char *arg1, char *arg2)
{
	int	i;
	while (arg1[i] || arg2[i])
	{
		if (arg1[i] == arg2[i])
			i++;
		return (arg1[i] - arg2[i]);
	}

}
int	main (int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;
	
	if (argc <= 1)
		return (0);
	i = 1;
	temp = &argv[i];
	while (argv[i])
		j = 0;
	

}
