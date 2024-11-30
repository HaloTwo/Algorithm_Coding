#include<bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) 
{    
    vector<string> strings;
    
    for(int num : numbers) 
    {
        strings.push_back(to_string(num));
    }
    
    sort(strings.begin(), strings.end(), [](auto a, auto b)
    {
        return a + b > b + a; 
    });
    
    string result;
    for(string s : strings) 
    {
        result += s;
    }
    
    if(result[0] == '0') return "0";
          
    return result;
}