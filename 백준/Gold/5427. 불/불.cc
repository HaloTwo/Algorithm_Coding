#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int T;

	cin >> T;

	while (T--)
	{
		int map[1001][1001]; // 0은 빈공간, 1은 벽, 2는 상근이, 3은 불

		queue<pair<int, int>> fireQ;
		int fireTime[1001][1001];    // 불이 도착하는 시간
		int playerTime[1001][1001];  // 상근이가 도착하는 시간

		int startX;
		int startY;

		int w, h; // 너비, 높이
		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char c;
				int num = 0;

				cin >> c;
				fireTime[i][j] = -1; // 먼저 초기화
				playerTime[i][j] = -1;

				//벽
				if (c == '#')
				{
					num = 1;
				}
				//플레이어
				else if (c == '@')
				{
					num = 2;
					startX = i;
					startY = j;
				}
				//불
				else if (c == '*')
				{
					num = 3;
					fireTime[i][j] = 0;
					fireQ.push({ i, j });
				}

				map[i][j] = num;  
			}
		}


		while (!fireQ.empty())
		{
			int curX = fireQ.front().first;
			int curY = fireQ.front().second;
			fireQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + curX;
				int ny = dy[i] + curY;

				//밖으로 나가면 안됌
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				//다음 공간이 벽이나 불이면 안됌
				if (map[nx][ny] == 1 || map[nx][ny] == 3) continue;
				//이미 지나간 공간이면 안됌
				if (fireTime[nx][ny] != -1) continue;

				fireTime[nx][ny] = fireTime[curX][curY] + 1;
				fireQ.push({ nx, ny });
			}
		}



		//플레이어 시간 측정
		queue<pair<int, int>> q;
		q.push({ startX, startY });
		playerTime[startX][startY] = 0;

		bool Sucess = false;

		while (!q.empty())
		{
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + curX;
				int ny = dy[i] + curY;

				//벽밖에로 넘어가면 성공
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				{
					cout << playerTime[curX][curY] + 1 << "\n";
					Sucess = true;
					break;
				}

				//불이거나 벽이면 안됌
				if (map[nx][ny] == 1 || map[nx][ny] == 3) continue;
				//겹치면 안됌 
				if (fireTime[nx][ny] != -1 && playerTime[curX][curY] + 1 >= fireTime[nx][ny]) continue;
				// 중복 방문 안됌
				if (playerTime[nx][ny] != -1) continue;

				playerTime[nx][ny] = playerTime[curX][curY] + 1;
				q.push({ nx, ny });
			}

			if (Sucess) break;
		}

		if (!Sucess)cout << "IMPOSSIBLE" << "\n";
	}

}