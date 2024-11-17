#include<bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    string answer = "";
    int idx = 0;  
    
    for(int i = 0; i < s.length(); i++) 
    {
        if(s[i] == ' ') 
        {
            answer += ' ';
            idx = 0;  
        } 
        else 
        {
            //짝수
            if(idx % 2 == 0) 
            {
                answer += toupper(s[i]);
            }
            //홀수
            else 
            {
                answer += tolower(s[i]);
            }
            idx++;
        }
    }
    
    return answer;
}