#include<bits/stdc++.h>
using namespace std;
int solution(string s) 
{
    int answer = s.size(); 
    
    for(int i = 1; i <= s.size() / 2; i++)
    {
        string compressed = "";  
        string prev = s.substr(0, i);  
        int count = 1;
        
        for(int j = i; j < s.size(); j += i)
        {
            string curr = s.substr(j, min(i, (int)(s.size() - j)));  // 여기 수정
            
            if(prev == curr)
            {
                count++;
            }
            else
            {
                if(count > 1) compressed += to_string(count);         
                compressed += prev;
                
                prev = curr;
                count = 1;
            }
        }
        
        // 마지막 문자열 처리
        if(count > 1) compressed += to_string(count);         
        compressed += prev;
        
        // 최소 길이 갱신
        answer = min(answer, (int)compressed.size());
    }
    
    return answer;
}