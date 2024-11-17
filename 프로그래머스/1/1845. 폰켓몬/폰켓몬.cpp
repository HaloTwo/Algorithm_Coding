#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) 
{
    unordered_map<int, int> phonekemon;
    
    int pick = nums.size() / 2;
    
    for(int num : nums) 
    {
        phonekemon[num]++;
    }
    
    int kinds = phonekemon.size();
    
    return min(kinds, pick);
}