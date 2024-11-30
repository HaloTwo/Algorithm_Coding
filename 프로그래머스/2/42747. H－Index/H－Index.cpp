#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) 
{   
    //내림차순
    sort(citations.begin(), citations.end(), greater<int>());
    
    // 3 0 6 1 5 -> 6 5 3 1 0
    
    for(int i = 0; i < citations.size(); i++)
    {
        if(i >= citations[i])  
        {
            return i;
        }
    }
    
    return citations.size();
}