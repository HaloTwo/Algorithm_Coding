#include<bits/stdc++.h>
using namespace std;

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};  
int dy[4] = {0, 0, -1, 1};  

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<pair<int,int>> q;
    
    q.push({0,0});
    visited[0][0] = true;
    maps[0][0] = 1;  
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == n-1 && y == m-1) 
        {
            return maps[x][y];
        }
              
        for(int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(maps[nx][ny] == 0 || visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            maps[nx][ny] = maps[x][y] + 1; 
            q.push({nx,ny});  // 새 위치 추가                  
        }    
    }
    return -1;
}