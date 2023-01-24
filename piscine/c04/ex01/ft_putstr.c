#include<unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str++, 1);
	}
}
int main()
{
	ft_putstr("hgsgavdf");
}
