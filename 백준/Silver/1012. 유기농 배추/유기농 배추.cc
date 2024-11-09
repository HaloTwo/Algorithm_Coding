#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y, int N, int M)  // N, M 추가
{
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;  // 범위 체크 수정
        if (visited[nx][ny] || graph[nx][ny] != 1) continue;
        dfs(graph, visited, nx, ny, N, M);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while(T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        
        vector<vector<int>> graph(N, vector<int>(M, 0));        // N행 M열로 수정
        vector<vector<bool>> visited(N, vector<bool>(M, false)); // N행 M열로 수정
        
        for(int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;
            if(X >= 0 && X < M && Y >= 0 && Y < N)  // 범위 체크 추가
                graph[Y][X] = 1;  // Y행 X열로 저장
        }
        
        int result = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(graph[i][j] == 1 && !visited[i][j])
                {
                    dfs(graph, visited, i, j, N, M);
                    result++;
                }
            }
        }
        
        cout << result << "\n";
    }
    return 0;
}