#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) 
{
    // 두 문자열을 모두 소문자로 변환
    string str_lower = my_string;
    string target_lower = target;
    
    for(char& c : str_lower) c = tolower(c);
    for(char& c : target_lower) c = tolower(c);
    
    return str_lower.find(target_lower) != string::npos ? 1 : 0;
}