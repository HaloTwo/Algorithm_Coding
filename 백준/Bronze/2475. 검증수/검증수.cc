#include <stdio.h>

int main()
{
	int n;
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);

		result += (n * n);
	}

	printf("%d", result % 10);

	return 0;
}

