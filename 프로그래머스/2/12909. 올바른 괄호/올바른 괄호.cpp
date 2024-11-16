#include <string>
#include <stack>

using namespace std;

bool solution(string s) 
{
    stack<char> stock;
    
    for(char c : s) 
    {
        if(c == '(') 
        {
            stock.push(c);
        }
        else if(c == ')') 
        {
            if(stock.empty()) return false;  
            
            stock.pop();
        }
    }
    
    return stock.empty();  
}