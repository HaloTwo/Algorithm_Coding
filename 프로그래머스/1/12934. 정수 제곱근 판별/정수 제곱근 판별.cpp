#include<bits/stdc++.h>

using namespace std;

long long solution(long long n) 
{
    long long sqrt_n = sqrt(n);
    
    if (sqrt_n * sqrt_n == n) 
    {
        return (sqrt_n + 1) * (sqrt_n + 1);
    }
    return -1;
}