#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	vector<int>dp(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> dp[i];
	}

	sort(dp.begin(), dp.end());

	int total = dp[0]; 
	int sum = dp[0];    

	for (int i = 1; i < N; i++)
	{
		sum += dp[i];
		total += sum;
	}

	cout << total;
}