#include <iostream>
#include <vector>
#include <queue>;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int M, N; // 가로 , 세로

	cin >> M >> N;

	vector<vector<int>> box(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//사과가 들어있는 시작점
			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		//4방향 검사
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			//벽이 아님
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				//안 먹은 토마토가 있으면 이동
				if (box[nx][ny] == 0)
				{
					box[nx][ny] = box[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	int result = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//안익은게 남아있따 ?
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			if (result <= box[i][j])
			{
				result = box[i][j];
			}
		}
	}

	cout << result - 1;

	return 0;
}

//

