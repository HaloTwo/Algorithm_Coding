#include<stdio.h>
#include<iostream>

int main()
{
	int n;
	long long int result = 0;
	char C[1000];

	scanf("%d", &n);
	scanf("%s", &C);

	for (int i = 0; i < n; i++)
	{
		result += C[i] - '0';
	}

	printf("%lld", result);

	return 0;
}