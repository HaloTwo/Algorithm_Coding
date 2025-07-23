#include <iostream>
#include <queue>

using namespace std;


const int MaxSize = 1001;

int map[MaxSize][MaxSize] = {}; // 0은 벽  / 1은 빈 공간 / 2는 지훈 / 3은 불

int fireTime[MaxSize][MaxSize];
int jihunTime[MaxSize][MaxSize];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int R, C;// 행 / 열

	int startX, startY;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int num = 0;
			char x;

			cin >> x;

			if (x == '#') num = 0;
			else if (x == '.') num = 1;
			else if (x == 'J')
			{
				num = 2;
				startX = i;
				startY = j;
			}
			else if (x == 'F') num = 3;

			map[i][j] = num;
		}
	}

	queue<pair<int, int>> fireQ;

	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize; j++)
		{
			fireTime[i][j] = -1;
			jihunTime[i][j] = -1;
		}
	}


	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] == 3)
			{
				fireQ.push({ i, j });
				fireTime[i][j] = 0; // 시작은 0초
			}
		}
	}

	while (!fireQ.empty())
	{
		int currentX = fireQ.front().first;
		int currentY = fireQ.front().second;
		fireQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + currentX;
			int ny = dy[i] + currentY;

			if (nx >= 0 && ny >= 0 && nx < R && ny < C && map[nx][ny] != 0 && fireTime[nx][ny] == -1)
			{
				fireTime[nx][ny] = fireTime[currentX][currentY] + 1;
				fireQ.push({ nx, ny });
			}
		}
	}

	queue<pair<int, int>> playerQ;

	jihunTime[startX][startY] = 0;
	playerQ.push({ startX, startY });

	while (!playerQ.empty())
	{
		int curX = playerQ.front().first;
		int curY = playerQ.front().second;
		playerQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + curX;
			int ny = dy[i] + curY;

			// 맵 밖이면 탈출 성공
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			{
				cout << jihunTime[curX][curY] + 1 << '\n';
				return 0;
			}

			// 가장 자리 탈출
			if (startX == 0 || startX == R - 1 || startY == 0 || startY == C - 1) {
				cout << 1 << '\n';
				return 0;
			}

			// 벽이면
			if (map[nx][ny] == 0) continue;

			// 이미 방문했으면
			if (jihunTime[nx][ny] != -1) continue;

			// 4. 불이 먼저 도착하거나 동시에 오면 안 감
			if (fireTime[nx][ny] != -1 && fireTime[nx][ny] <= jihunTime[curX][curY] + 1) continue;

			// 5. 이동 가능 → 큐에 추가
			jihunTime[nx][ny] = jihunTime[curX][curY] + 1;
			playerQ.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
