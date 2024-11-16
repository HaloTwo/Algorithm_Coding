#include <string>

using namespace std;

bool solution(string s) 
{
    bool answer = true;
    int size = s.size();
    
    if(size != 4 && size != 6)
    {
        return false;
    }
    
    for(int i = 0; i < s.size(); i++)
    {
        if(!isdigit(s[i]))
        {
            answer = false;
            break;
        }   
    }
      
    return answer;
}