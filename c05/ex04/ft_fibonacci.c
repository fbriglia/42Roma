int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(nb -1) + ft_fibonacci(nb - 2));
}
