#include<stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	res;
	
	res = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return(0);
	while(nb > 1)
	{
		res = res  * (nb -1);
		nb--;
	}
	return (res);
}
/*
int main ()
{
	printf("%d",ft_iterative_factorial(5));

}
*/
