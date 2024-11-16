#include <string>

using namespace std;

string solution(string s) 
{
    int len = s.length();
    
     // 홀수
    if(len % 2 == 1) 
    {
        return s.substr(len/2, 1);
    } 
    // 짝수
    else 
    {
        return s.substr(len/2-1, 2);
    }

}