#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y, int N, int M)  // N, M 추가
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny] || graph[nx][ny] != 1) continue;
		dfs(graph, visited, nx, ny, N, M);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;

		vector<vector<int>> graph(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));

		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			graph[Y][X] = 1;
		}

		int result = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (graph[i][j] == 1 && !visited[i][j])
				{
					dfs(graph, visited, i, j, N, M);
					result++;
				}
			}
		}

		cout << result << "\n";
	}
	return 0;
}