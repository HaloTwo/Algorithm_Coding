#include <string>
#include <vector>

using namespace std;

string solution(string myString) 
{
    for(auto& str : myString)
    {
        if(str == 'a'|| str == 'A')
        {
            str = toupper(str);
        }
        else
        {
            str = tolower(str);
        }
    }
    
    
    
    return myString;
}