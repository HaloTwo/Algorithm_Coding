#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    while (cin >> n) 
    {  
        if (n == 0) break;

        string str = to_string(n);
        bool isPalindrome = true;

        for (int i = 0; i < str.size() / 2; i++) 
        {
            if (str[i] != str[str.size() - 1 - i]) 
            {
                isPalindrome = false;
                break;
            }
        }

        cout << (isPalindrome ? "yes" : "no") << "\n";
    }
    return 0;
}