#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	int dx[4] = { 0, -1, 1, 0 };  // 위, 왼, 오른, 아래  (x 변화)
	int dy[4] = { -1, 0, 0, 1 };  // 위, 왼, 오른, 아래  (y 변화)

	cin >> N;

	vector<vector<int>> map(N, vector<int>(N));

	int startX = -1;
	int startY = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 9)
			{
				startX = j;
				startY = i;
				map[i][j] = 0; // 시작점은 빈칸으로 바꿔둠
			}
		}
	}


	int sharkSize = 2;
	int eatCnt = 0;
	int resultTime = 0;

    while (true)
    {
        vector<vector<int>> dist(N, vector<int>(N, -1));
        queue<pair<int, int>> q;

        q.push({ startX, startY });
        dist[startY][startX] = 0;

        int targetX = -1, targetY = -1, minDist = 1e9;

        while (!q.empty())
        {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nextX = curX + dx[d];
                int nextY = curY + dy[d];

                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
                if (dist[nextY][nextX] != -1) continue;
                if (map[nextY][nextX] > sharkSize) continue;

                dist[nextY][nextX] = dist[curY][curX] + 1;

                // 먹을 수 있는 물고기
                if (map[nextY][nextX] > 0 && map[nextY][nextX] < sharkSize)
                {
                    int dcur = dist[nextY][nextX];
                    if (dcur < minDist ||
                        (dcur == minDist && (nextY < targetY || (nextY == targetY && nextX < targetX))))
                    {
                        minDist = dcur;
                        targetX = nextX;
                        targetY = nextY;
                    }
                }

                q.push({ nextX, nextY });
            }
        }

        if (targetX == -1) break; // 먹을 수 있는 물고기 없음

        resultTime += minDist;
        eatCnt++;
        if (eatCnt == sharkSize)
        {
            sharkSize++;
            eatCnt = 0;
        }

        startX = targetX;
        startY = targetY;
        map[startY][startX] = 0; // 먹은 자리 빈칸으로
    }

    cout << resultTime << "\n";
    return 0;
}
