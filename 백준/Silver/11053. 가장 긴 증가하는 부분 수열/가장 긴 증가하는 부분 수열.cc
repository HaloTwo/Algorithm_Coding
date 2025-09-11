#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> dp(N, 1); 
	int result = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < N; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (arr[j] < arr[i]) 
			{
				dp[i] = max(dp[i], dp[j] + 1); 
			}
		}

		result = max(result, dp[i]); 
	}

	cout << result;
	return 0;
}
