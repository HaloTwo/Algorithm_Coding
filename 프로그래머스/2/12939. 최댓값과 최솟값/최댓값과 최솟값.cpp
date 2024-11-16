#include<bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    stringstream ss(s);
    vector<int> nums;
    int num;
    
    while(ss >> num)
    {
        nums.push_back(num);
    }   
    
    sort(nums.begin(), nums.end());
       
    
    answer = to_string(nums.front())+' '+to_string(nums.back());
    
    return answer;
}