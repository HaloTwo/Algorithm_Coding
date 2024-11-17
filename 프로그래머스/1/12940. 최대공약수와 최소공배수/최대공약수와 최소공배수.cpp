#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) 
{
    if(b != 0) 
    {
        return gcd(b, a % b);
    } 
    else 
    {
        return a;
    }
}

int lcm(int a, int b) 
{
    return a * b / gcd(a, b);
}

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    
    int g = gcd(n, m);
    int l = lcm(n, m);
    
    answer.push_back(g);
    answer.push_back(l);
    
    
    return answer;
}