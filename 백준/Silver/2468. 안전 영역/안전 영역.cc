#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>  
#include<cstring>  

using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int N;
	int graph[101][101];
	bool visited[101][101];

	int dx[4] = { 0 ,0, 1, -1 };
	int dy[4] = { 1 ,-1, 0, 0 };


	cin >> N;

	int minNum = 100;
	int maxNum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			cin >> x;
			graph[i][j] = x;

			minNum = min(minNum, x);
			maxNum = max(maxNum, x);
		}
	}

	int result = 0;

	for (int rainHeight = 0; rainHeight <= maxNum; rainHeight++)
	{
		memset(visited, false, sizeof(visited));
		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && graph[i][j] > rainHeight)
				{
					queue<pair<int, int>> q; 
					q.push({ i, j });
					visited[i][j] = true;
					cnt++;

					while (!q.empty())
					{
						int cy = q.front().first;
						int cx = q.front().second;
						q.pop();

						for (int d = 0; d < 4; d++)
						{
							int ny = cy + dy[d];
							int nx = cx + dx[d];

							if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
							if (visited[ny][nx]) continue;
							if (graph[ny][nx] <= rainHeight) continue;

							q.push({ ny, nx });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}

		result = max(result, cnt);
	}
	cout << result << '\n';

	return 0;
}