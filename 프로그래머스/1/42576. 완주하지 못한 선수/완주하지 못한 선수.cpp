#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    
    unordered_map<string, int> maratonPerson;
    
    for(auto participants : participant)
    {
        maratonPerson[participants]++;
    }
    
    for(auto completions : completion)
    {
        maratonPerson[completions]--;
    }
    
    for(auto maratonPersons : maratonPerson)
    {
        if(maratonPersons.second > 0)
        {
            answer = maratonPersons.first;
            break;
        };
    }  
    
    return answer;
}