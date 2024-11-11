#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, X, Y;

	cin >> N >> M;

	vector<int> W(N + 1);	//무게
	vector<int> V(N + 1);	//가치
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	int** dp = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = new int[M + 1];
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			dp[i][j] = 0;
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + V[i]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{ 
			// 현재 물건의 무게가 가방 용량보다 작거나 같을 때만!
			if (W[i] <= j)
			{ //                   물건을 안 넣는 경우 / 물건을 넣는 경우
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else 
			{ 
				// 물건이 너무 무거우면
				dp[i][j] = dp[i - 1][j];   // 이전 상태 그대로 가져오기
			}
		}
	}

	cout << dp[N][M];
}