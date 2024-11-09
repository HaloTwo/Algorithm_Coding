#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char campus[601][601];
bool visited[601][601] = { false };

// 상하좌우 이동용
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int result = 0;  // 만난 사람 수

void dfs(int x, int y)
{
	visited[x][y] = true;

	if (campus[x][y] == 'P') result++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;  // 범위 체크
		if (visited[nx][ny] || campus[nx][ny] == 'X') continue;  // 방문했거나 벽인 경우

		dfs(nx, ny);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int StartX, StartY;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> campus[i][j];

			if (campus[i][j] == 'I')
			{
				StartX = i;
				StartY = j;
			}
		}
	}

	dfs(StartX, StartY);

	if (result != 0)
	{
		cout << result;
	}
	else 
	{
		cout << "TT";
	}


	return 0;
}