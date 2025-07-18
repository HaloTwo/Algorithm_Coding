#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int dx[4] = { -1, 0, 1, 0 }; // 북 동 남 서
    int dy[4] = { 0, 1, 0, -1 };

	int N, M; // 방의 크기
	int r, c, d; // (r,c) 시작 좌표, d는 방향 북동남서
	int cnt = 0;

	cin >> N >> M;
	cin >> r >> c >> d;

	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{
		//조건1 현재 칸이 청소되지 않았으면 청소
		if (map[r][c] == 0)
		{
			map[r][c] = 2;
			cnt++;
		}

		bool allCleaned = true;

		//모든 방향 확인
		for (int i = 0; i < 4; i++)
		{
			// 왼쪽 방향으로 회전
			d = (d + 3) % 4;

			int nx = r + dx[d];
			int ny = c + dy[d];

			// 청소 안 된 칸 발견하면 이동
			if (map[nx][ny] == 0)
			{
				r = nx;
				c = ny;
				allCleaned = false;
				break; // 다음 while에서 다시 조건1으로 감
			}
		}

		//모든 칸이 깨끗하면 후진 확인
		if (allCleaned)
		{
			int back_dir = (d + 2) % 4;
			int bx = r + dx[back_dir];
			int by = c + dy[back_dir];

			// 벽이라서 작동 멈춤
			if (map[bx][by] == 1)
			{
				cout << cnt;
				return 0;
			}

			r = bx;
			c = by;
		}
	}

	return 0;
}

//조건1: 현재 칸이 청소되지 않은 경우, 현재칸을 청소한다.

//조건2: 현재 칸의 모든 방향이 청소된 경우에는,
//현재 바라보는 방향에서 뒤로 갈 수 있으면 후진하고 조건1로 이동, 
//벽이라 못가면 작동 정지

//조건3: 현재 칸의 모든 방향 중 청소되지 않는 빈칸이 있는 경우에는,
//반시계 방향으로 90도 회전하고 앞쪽 칸이 청소되지 않는 칸이면 전진 후 조건1 이동
