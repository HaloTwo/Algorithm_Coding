#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    for (char c = 'a'; c <= 'z'; c++)
    {
        cout << (int)s.find(c) << " ";
    }

    return 0;
}