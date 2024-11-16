#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{ 
    int smallnum = 10001;
    int arrindex = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(smallnum > arr[i])
        {
            smallnum = arr[i];
            arrindex = i;
        }      
    }
   
    arr.erase(arr.begin()+arrindex);
      
    if(arr.empty())
    {
        arr.push_back(-1);
    }
       
    return arr;
}