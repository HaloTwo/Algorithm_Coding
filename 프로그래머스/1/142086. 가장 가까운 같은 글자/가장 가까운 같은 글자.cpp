#include<bits/stdc++.h>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    unordered_map<char, int> saveMap;

    for(int i = 0; i < s.size(); i++)
    {

        if(saveMap.find(s[i]) != saveMap.end()) 
        {
            answer.push_back(i - saveMap[s[i]]);
            saveMap[s[i]] = i;           
        }
        else 
        {
            saveMap.insert({s[i],i});
            answer.push_back(-1);

        }
    }

    return answer;

}