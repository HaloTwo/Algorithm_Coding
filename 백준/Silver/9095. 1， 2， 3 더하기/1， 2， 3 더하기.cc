#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	vector<int> dp(11);

	// 초기값 설정
	dp[1] = 1;  
	dp[2] = 2; 
	dp[3] = 4;  

	for (int i = 4; i <= 10; i++) 
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		cout << dp[m] << "\n";
	}

	return 0;
}