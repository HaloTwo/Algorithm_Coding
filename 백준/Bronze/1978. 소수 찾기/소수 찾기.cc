#include <stdio.h>

bool isPrime(int num)
{
	int cnt = 0;

	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0) cnt++;
	}

	if (cnt == 2) return true;

	return false;
}

int main()
{
	int n, m;
	int result = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);

		if (isPrime(m))
		{
			result++;
		}
	}

	printf("%d", result);


	return 0;
}

