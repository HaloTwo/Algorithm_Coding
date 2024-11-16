#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
    string answer = "";
    
    for(int i = 1; i <= n; i++)
    {
        //짝수
       if(i%2 == 0)
       {
           answer+="박";
       }
        //홀수
        else if(i%2 == 1)
        {
            answer+="수";
        }       
    }
    
    
    return answer;
}