#include<bits/stdc++.h>
using namespace std;
int solution(string my_string, string is_prefix) 
{
    // 접두사인지 확인하려면 문자열의 시작부분만 확인하면 됩니다
    if(my_string.substr(0, is_prefix.size()) == is_prefix) 
    {
        return 1;
    }
    return 0;
}