#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int>> dp(40);

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i <= 40; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;  
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	int T, N;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << dp[N].first << " " << dp[N].second << "\n";
	}

	return 0;
}