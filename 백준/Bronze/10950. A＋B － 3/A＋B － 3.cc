#include <stdio.h>

int main()
{
	int n= 1, x= 2, y = 5;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", x+y);
	}

	return 0;
}

