void	ft_putnbr(int nb)
{
	int 	i;
	char	c;
	
	i = 0;
	if (nb < 0)
	{
		write(1, '-', 1);
		nb = nb * -1;
	}
	if (nb > 10)
		ft_putnbr(nb/10);
	else
	{
		c = nb % 10 + '0';
		write(1, &c, 1);
	}	
}
