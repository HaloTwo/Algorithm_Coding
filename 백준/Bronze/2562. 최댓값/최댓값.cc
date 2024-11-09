#include<stdio.h>

int main()
{
	int n;
	int maxNum = 0;
	int num = 0;

	for (int i = 1; i <= 9; i++)
	{
		scanf("%d", &n);

		if (maxNum < n)
		{
			maxNum = n;
			num = i;
		}
	}

	printf("%d\n%d", maxNum, num);

	return 0;
}