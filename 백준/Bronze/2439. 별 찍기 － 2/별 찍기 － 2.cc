#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; n - i> j; j++)
		{
			printf(" ");
		}

		for (int j = 0; i > j; j++)
		{
			printf("*");
		}

		printf("\n");
	}


	return 0;
}