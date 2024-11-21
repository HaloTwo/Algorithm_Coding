#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
   string s;
   cin >> s;
   
   for(char& c : s) 
   {
       c = toupper(c);
   }
   
   vector<int> count(26, 0);
   for(char c : s) 
   {
       count[c - 'A']++;
   }
   
   int maxCount = 0;
   char maxAlpha = '?';
   
   for(int i = 0; i < 26; i++) 
   {
       if(count[i] > maxCount) 
       {
           maxCount = count[i];
           maxAlpha = 'A' + i;
       }
       else if(count[i] == maxCount) 
       {
           maxAlpha = '?';
       }
   }
   
   cout << maxAlpha;
}