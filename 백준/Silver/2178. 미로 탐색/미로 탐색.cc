#include<bits/stdc++.h>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // 세로방향 이동 (상하)
int dy[4] = { 0, 0, -1, 1 };  // 가로방향 이동 (좌우)

void bfs(vector<vector<int>>& map, vector<vector<bool>>& isvisited, int startX, int startY)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ {startX, startY}, 1 });
    isvisited[startX][startY] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if (x == map.size() - 1 && y == map[0].size() - 1)
        {
            cout << dist;  // 도착점에 도달하면 거리 출력
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size()) continue;
            if (isvisited[nx][ny] || map[nx][ny] == 0) continue;  // 여기를 수정! 1이 길이므로
            isvisited[nx][ny] = true;
            q.push({ {nx,ny}, dist + 1 });
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;

	cin >> x >> y;

	vector<vector<int>> map(x, vector<int>(y, 0));
	vector<vector<bool>> isvisited(x, vector<bool>(y, false));

	for (int i = 0; i < x; i++)
	{
        string s;
        cin >> s;

		for (int j = 0; j < y; j++)
		{
			 map[i][j] = s[j]-'0';
		}
	}

    bfs(map, isvisited, 0, 0);

	return 0;
}