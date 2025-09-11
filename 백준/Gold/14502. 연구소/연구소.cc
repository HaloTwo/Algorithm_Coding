#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
	queue<pair<int, int>> q;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
			{
				q.push({ i,j });
			}
		}
	}


	//전체탐색 3개 벽 세우기
	for (int i = 0; i < N * M; i++)
	{
		for (int j = i+1; j < N * M; j++)
		{
			for (int k = j+1; k < N * M; k++)
			{
				int y1 = i / M;
				int y2 = j / M;
				int y3 = k / M;

				int x1 = i % M;
				int x2 = j % M;
				int x3 = k % M;

				//빈공간이 아니면 패스
				if (map[y1][x1] != 0 || map[y2][x2] != 0 || map[y3][x3] != 0) continue;

				vector<vector<int>> temp = map;
				queue<pair<int, int>> tempq = q;

				//복사본에 각각 3곳에 벽 세우기
				temp[y1][x1] = temp[y2][x2] = temp[y3][x3] = 1;


				while (!tempq.empty())
				{
					int curY = tempq.front().first;
					int curX = tempq.front().second;
					tempq.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int ny = curY + dy[dir];
						int nx = curX + dx[dir];

						if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
						if (temp[ny][nx] != 0) continue;

						temp[ny][nx] = 2;  
						tempq.push({ny, nx});
					}
				}

				int count = 0;

				for (int x = 0; x < N; x++)
				{
					for (int y = 0; y < M; y++)
					{
						if (temp[x][y] == 0)
						{
							count++;
						}
					}
				}

				result = max(result, count);
			}
		}
	}

	cout << result;


	return 0;
}
