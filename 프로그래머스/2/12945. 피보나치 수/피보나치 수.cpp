#include<bits/stdc++.h>

using namespace std;

int solution(int n) 
{    
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) % 1234567;
    }
           
    return dp[n];
}