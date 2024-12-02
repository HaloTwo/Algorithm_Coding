#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) 
{
   int count = 0;
   int len = p.length();
   
   for(int i = 0; i <= t.length() - len; i++) 
   {
       string sub = t.substr(i, len);
       
       if(sub <= p) count++;
   }
   
   return count;
}