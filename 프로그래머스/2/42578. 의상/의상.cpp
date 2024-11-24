#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    
    unordered_map<string, int> corrd;
    
    for(int i = 0; i < clothes.size(); i++) 
    {
        corrd[clothes[i][1]]++;  
    }
    
    for(auto corrds : corrd)
    {
        answer*=(corrds.second+1); 
    }
    answer--;
          
    return answer;
}