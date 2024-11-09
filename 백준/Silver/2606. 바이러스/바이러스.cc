#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& computer, vector<bool>& check, int startNum)
{
	check[startNum] = true;

	for (int i = 0; i < computer[startNum].size(); i++)
	{
		int next = computer[startNum][i];

		if (!check[next])
		{
			dfs(computer, check, next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N, M, X, Y;

	cin >> N;
	cin >> M;

	vector<vector<int>> computer(N + 1);
	vector<bool> check(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		computer[X].push_back(Y);
		computer[Y].push_back(X);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(computer[i].begin(), computer[i].end());
	}

	dfs(computer, check, 1);

	int count = 0;
	for (int i = 2; i <= N; i++)
	{
		if (check[i]) count++;
	}

	cout << count << "\n";
}