#include <string>
#include <vector>

using namespace std;

bool visited[200] = {false};

void dfs (int node, vector<vector<int>>& computers)
{
    visited[node] = true;
    
    for(int i = 0; i < computers.size(); i++)
    {
      if (i != node && computers[node][i] == 1 && !visited[i])
        {
            dfs(i, computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, computers);
            answer++;
        }      
    }  
    return answer;
}