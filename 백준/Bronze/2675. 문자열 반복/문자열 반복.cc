#include<stdio.h>

int main()
{
	int n, count;
	char c[10000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &count, c);

		for (int j = 0; c[j] != '\0'; j++)
		{
			for (int k = 0; k < count; k++)
			{
				printf("%c", c[j]);
			}
		}
		printf("\n");
	}

	return 0;
}