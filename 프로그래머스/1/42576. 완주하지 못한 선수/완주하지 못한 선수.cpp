#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    
    unordered_map<string, int> maratonPerson;
    
    
    for(auto name : participant) 
    {
        maratonPerson[name]++;
    }
    
    for(auto name : completion) 
    {
        maratonPerson[name]--;
    }
    
    
    for(auto itr : maratonPerson) 
    {
        if(itr.second > 0) 
        {
            answer=itr.first;
        }
    }
    
    return answer;
}