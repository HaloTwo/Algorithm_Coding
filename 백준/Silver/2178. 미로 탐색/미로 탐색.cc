#include<bits/stdc++.h>
using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& map, vector<vector<int>>& dist, int x, int y)
{
    queue<pair<int, int>> que;  
    que.push({ x, y });
    dist[x][y] = 1;  

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size()) continue;
            if (dist[nx][ny] || map[nx][ny] == 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push({ nx, ny });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, 0));  

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    bfs(map, dist, 0, 0);
    cout << dist[n - 1][m - 1];  
    return 0;
}