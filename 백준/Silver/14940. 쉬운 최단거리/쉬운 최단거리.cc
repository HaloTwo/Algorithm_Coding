#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	int n, m;
	int startX, startY;

	cin >> n >> m;
	int map[1000][1000];
	int dist[1000][1000];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;

			map[i][j] = num;
			dist[i][j] = -1;

			if (num == 2)
			{
				startX = i;
				startY = j;
			}
		}
	}

	int dx[4] = { 0 , 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };


	queue<pair<int, int>> q;

	q.push({ startX, startY });
	dist[startX][startY] = 0;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + curX;
			int nextY = dy[i] + curY;

			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
			if (dist[nextX][nextY] != -1)continue;
			if (map[nextX][nextY] == 0) continue;

			q.push({ nextX, nextY });
			dist[nextX][nextY] = dist[curX][curY] + 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
}
