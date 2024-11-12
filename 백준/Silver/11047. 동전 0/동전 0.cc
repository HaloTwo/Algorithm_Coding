#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;

	cin >> N >> K;

	vector<int> coins(N);
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	int count = 0;  // 동전 개수
	int money = K;  // 남은 금액

	//큰수부터 빼기
	for (int i = N - 1; i >= 0; i--)
	{
		while (money >= coins[i])
		{
			money -= coins[i];
			count++;
		}
	}

	cout << count;
}