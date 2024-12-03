#include<bits/stdc++.h>

using namespace std;

int solution(string binomial) 
{
    int answer = 0;
    
    stringstream ss(binomial);
    string word;
    
    vector<int> num;
    string op;
    
    while(ss >> word)
    {
        if(isdigit(word[0]))
        {
            num.push_back(stoi(word));
        }
        else
        {
            op = word;
        }        
    }
    
    if(op == "+") return num[0] + num[1];
    if(op == "-") return num[0] - num[1];
    if(op == "*") return num[0] * num[1];
    if(op == "/") return num[0] / num[1];
    
       
    return answer;
}