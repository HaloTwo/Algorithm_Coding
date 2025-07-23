#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int board[101][101] = { 0 }; // 0: 빈칸, 1: 사과, 2: 뱀
int dx[4] = { 0, 1, 0, -1 }; // 동, 남, 서, 북
int dy[4] = { 1, 0, -1, 0 };
int dir = 0; // 처음엔 오른쪽 (동)

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int N, K;// NxN 크기 / K는 사과갯수

	deque<pair<int, int>> snake;

	cin >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1; // 사과 위치
	}

	int L;
	cin >> L;

	vector<pair<int, char>> directions;

	for (int i = 0; i < L; ++i)
	{
		int X; char C;
		cin >> X >> C;
		directions.push_back({ X, C });
	}

	snake.push_back({ 1, 1 });
	board[1][1] = 2;

	int time = 0; // 시간
	int turnIdx = 0; // 방향 전환 인덱스 

	while (true)
	{
		time++;

		// 다음 위치 계산
		int headX = snake.back().first;
		int headY = snake.back().second;

		int nx = headX + dx[dir];
		int ny = headY + dy[dir];

		// 벽 또는 자기 몸에 부딪히면 종료
		if (nx <= 0 || ny <= 0 || nx > N || ny > N || board[nx][ny] == 2)
			break;

		//사과가 있으면 길이를 늘리기
		if (board[nx][ny] == 1)
		{
			board[nx][ny] = 2;
			snake.push_back({ nx, ny });
		}
		//빈칸이면 이동하고 길이를 줄이기
		else
		{
			board[nx][ny] = 2;
			snake.push_back({ nx, ny });

			board[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}

		//방향전환 시간이 되었으면
		if (time == directions[turnIdx].first && turnIdx < directions.size())
		{
			char turn = directions[turnIdx].second;

			if (turn == 'L')
			{
				dir = (dir + 3) % 4;
			}
			else if (turn == 'D')
			{
				dir = (dir + 1) % 4;
			}

			turnIdx++;
		}
	}
	cout << time << '\n';

	return 0;
}
