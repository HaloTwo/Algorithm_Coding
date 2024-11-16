#include<bits/stdc++.h>

using namespace std;

int solution(int num) 
{
    long long n = num;
    int answer = 0;
    
    if(n == 1)
    {
        return 0;
    }
    
    while(n > 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
        }
        else if(n % 2 == 1)
        {
            n = n * 3 + 1;
        }
              
        answer++;
        if(answer >= 500) 
        {
             return -1;
        }
    }
      
    return answer;
}