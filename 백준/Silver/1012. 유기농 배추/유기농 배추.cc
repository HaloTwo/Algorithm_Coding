#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51];
bool visited[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int M, int N)
{
	visited[x][y] = true;

	//4방향 검사
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N)
		{
			if (map[nx][ny] == 1 && !visited[nx][ny])
			{
				dfs(nx, ny, M, N);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, M, N, K;

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)  
		{
			int x, y;
			cin >> x >> y;

			map[x][y] = 1; // 배추 심기
		}

		int cnt = 0; 

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 1 && !visited[i][j])
				{
					dfs(i, j, M, N);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}

	return 0;
}
