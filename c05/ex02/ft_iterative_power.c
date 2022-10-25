#include<stdio.h>
int	ft_iterative_power(int nb, int power)
{
	int x;
	int	result;

	result = nb;
	x = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return(1);
	if (nb == 0)
		return (0);
	while (x < power)
	{
		result = result * nb;
		x++;
	}
	return (result);
}
int main ()
{
	printf("%d",ft_iterative_power(12, 999999999));
}
