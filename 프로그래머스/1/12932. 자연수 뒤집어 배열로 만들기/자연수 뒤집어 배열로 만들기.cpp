#include<bits/stdc++.h>

using namespace std;

vector<int> solution(long long n) 
{

    
    string str = to_string(n);
    vector<int> answer(str.size());
    
    
    for(int i = 0; i < str.size(); i++)
    {
        answer[str.size()-(i+1)] = str[i] - '0';      
    }
    
    
    
    
    return answer;
}