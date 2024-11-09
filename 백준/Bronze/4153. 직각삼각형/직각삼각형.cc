#include <stdio.h>

int main() 
{
	long int x, y, z;

	while (true)
	{
		scanf("%ld %ld %ld", &x, &y, &z);

		if (x == 0 && y == 0 && z == 0) break;

		if ((x * x) + (y * y) == (z * z) ||
			(x * x) + (z * z) == (y * y) ||
			(z * z) + (y * y) == (x * x))
		{
			printf("right\n");
		}
		else
		{
			printf("wrong\n");
		}
	}

	return 0;
}