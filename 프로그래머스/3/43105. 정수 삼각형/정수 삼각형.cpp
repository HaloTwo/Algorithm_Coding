#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer;
    
    vector<vector<int>> dp = triangle; 
    
    for(int i = 1; i < triangle.size(); i++) 
    { 
        for(int j = 0; j <= i; j++) 
        { 
            if(j == 0) 
            {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j == i) 
            {  // 마지막 열 처리 필요
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    sort(dp[triangle.size()-1].rbegin(), dp[triangle.size()-1].rend());
    
    answer = dp[triangle.size()-1].front();

    return answer;
}