int	ft_recursive_factorial(int nb)
{
	int res;

	res = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return(0);
	else if (nb > 0)
	{
		res = res * (nb - 1);
		ft_recursive_factorial(nb - 1);
	}
	return (res);
}
int main ()
{
	ft_recursive_factorial(5);
}
