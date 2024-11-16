#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    unordered_map<string, string> nickNameSlot;
    vector<pair<string, string>> commands; 
    
    for(const auto &records : record)
    {    
        
        stringstream ss(records);
        string command, id, nickname;
        ss >> command;
        
        if(command == "Enter") 
        {
            ss >> id >> nickname;
            nickNameSlot[id] = nickname; 
            commands.push_back({command, id});
        }
        else if(command == "Leave") 
        {
            ss >> id;            
            commands.push_back({command, id});
        }
        else if(command == "Change")
        {
            ss >> id >> nickname;
            nickNameSlot[id] = nickname;  
        }
        
    }
    
    for(auto com : commands)
    {  
        if(com.first == "Enter")
        {
            answer.push_back(nickNameSlot[com.second] + "님이 들어왔습니다.");           
        }
        else if(com.first == "Leave")
        {
            answer.push_back(nickNameSlot[com.second] + "님이 나갔습니다.");     
        }    
    }
       
    
    return answer;
}