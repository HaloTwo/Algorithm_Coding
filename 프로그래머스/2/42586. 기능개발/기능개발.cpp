#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        q.push(ceil((100 - progresses[i]) / (double)speeds[i]));
    }
    

    while(!q.empty()) 
    {
        int cur = q.front();  
        q.pop();
        int cnt = 1;  
        
        while(!q.empty() && q.front() <= cur) 
        {
            cnt++;
            q.pop();
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}