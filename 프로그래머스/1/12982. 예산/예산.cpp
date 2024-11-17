
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    int add = 0;
    
    sort(d.begin(), d.end());
    
    for(int i = 0; i < d.size(); i++)
    {
      
        add += d[i];
        answer++;
        
        if(add > budget)
        {
            add -= d[i];
            answer--;
            break;
        }
    }
    
    
    
    return answer;
}