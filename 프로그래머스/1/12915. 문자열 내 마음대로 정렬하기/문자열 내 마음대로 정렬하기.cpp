#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strings, int n) 
{
    vector<pair<string, string>> temp;
    
    for(auto s : strings) 
    {
        temp.push_back({s[n] + s, s});  
    }
    
    sort(temp.begin(), temp.end());
    
    vector<string> result;
    for(auto p : temp) 
    {
        result.push_back(p.second);
    }
    
    return result;
}