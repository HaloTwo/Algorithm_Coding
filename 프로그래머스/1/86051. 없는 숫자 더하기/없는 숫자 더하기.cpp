#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) 
{
    int sum = 45;  
    
    for(int num : numbers) 
    {
        sum -= num;
    }
    
    return sum;
}