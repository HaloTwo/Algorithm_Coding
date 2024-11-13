#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;

    while (true)
    {
        getline(cin, str);
        if (str == ".") break;

        stack<char> st;
        bool isbool = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '[' || str[i] == '(') 
            {
                st.push(str[i]);
            }
            else if (str[i] == ']') 
            {
                if (st.empty() || st.top() != '[') 
                {  
                    isbool = false;
                    break;
                }
                st.pop();
            }
            else if (str[i] == ')') 
            {
                if (st.empty() || st.top() != '(')
                {  
                    isbool = false;
                    break;
                }
                st.pop();
            }
        }

        cout << (isbool && st.empty() ? "yes" : "no") << "\n";
    }
    return 0;
}