#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int dx[4] = { 0 ,1, -1, 0 };
	int dy[4] = { 1, 0, 0, -1 };

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M, false));



	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] != 1) continue;

			visited[ny][nx] = true;
			map[ny][nx] = map[curY][curX] + 1;  // 거리 누적
			q.push({ ny, nx });
		}
	}


	cout << map[N-1][M-1];

	return 0;
}
