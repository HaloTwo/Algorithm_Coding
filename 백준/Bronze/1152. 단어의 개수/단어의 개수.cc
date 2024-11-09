#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    getline(cin, str); 

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    if (str[0] == ' ') count--;
    if (str[str.length() - 1] == ' ') count--;
    cout << ++count;

    return 0;
}