#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    for(auto command : commands) 
    {
        vector<int> arr = array;  
        
        arr.erase(arr.begin() + command[1], arr.end());
        arr.erase(arr.begin(), arr.begin() + (command[0] - 1));
        
        sort(arr.begin(), arr.end());
        
        answer.push_back(arr[command[2] - 1]);
    }
    
    return answer;
}