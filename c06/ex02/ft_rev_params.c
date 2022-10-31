#include<unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int x;

	x = argc;
	while (x-- > 1)
	{
		i = 0;
		while (argv[x][i] != 0)
		{
			write(1, &argv[x][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
