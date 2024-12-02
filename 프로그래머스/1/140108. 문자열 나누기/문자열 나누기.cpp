#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 1;
    int firstNum = 1;
    int otherNum = 0;
    char firstChar = s[0];
    
    for(int i = 1; i < s.length(); i++) 
    {
        if(firstChar == s[i]) 
        {
            firstNum++;
        } 
        else 
        {
            otherNum++;
        }
        
        if(firstNum == otherNum) 
        {
            if(i < s.length() - 1) 
            {
                answer++;
                firstChar = s[i + 1];
                firstNum = 1;
                otherNum = 0;
                i++;
            }
        }
    }
    
    return answer;
}