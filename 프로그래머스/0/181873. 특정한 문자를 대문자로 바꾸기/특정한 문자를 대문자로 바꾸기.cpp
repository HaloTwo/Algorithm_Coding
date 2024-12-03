#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) 
{    
    for(auto& chars : my_string)
    {
        if(chars == alp[0])
        {
            chars = toupper(chars);
        }       
    }
    
    
    return my_string;
}