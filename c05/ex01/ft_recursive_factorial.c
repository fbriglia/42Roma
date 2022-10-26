int	ft_recursive_factorial(int nb)
{
	int res;

	res = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return(0);
	return (ft_recursive_factorial(nb -1) * nb);
}
/*
int main ()
{
	ft_recursive_factorial(5);
}
*/
