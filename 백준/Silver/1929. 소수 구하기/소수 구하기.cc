#include <iostream>
using namespace std;

bool isPrime(int n)
{
	//2 이하는 아님
	if (n < 2) return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		if (isPrime(i))
		{
			cout << i << '\n';
		}
	}
	return 0;
}