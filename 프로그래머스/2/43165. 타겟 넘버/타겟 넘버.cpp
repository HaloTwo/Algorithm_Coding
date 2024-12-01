#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int target, int depth, int sum)
{
    if(depth == numbers.size())
    {
        if(sum == target) answer++;  
        return;
    }
    
    // 2. 현재 숫자를 더하는 경우
    dfs(numbers, target, depth + 1, sum + numbers[depth]);
    
    // 3. 현재 숫자를 빼는 경우
    dfs(numbers, target, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) 
{
    dfs(numbers, target, 0, 0);
    return answer;
}