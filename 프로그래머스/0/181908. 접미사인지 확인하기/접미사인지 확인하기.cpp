#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) 
{

    if(my_string.length() < is_suffix.length()) 
    {
        return 0;
    }
    
    if(my_string.substr(my_string.size() - is_suffix.size()) == is_suffix) 
    {
        return 1;
    }
    
    return 0;
}