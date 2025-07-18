#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> stk;
    vector<char> result;

    int cur = 1; // 현재 넣을 숫자
    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        // cur까지 push
        while (cur <= x)
        {
            stk.push(cur++);
            result.push_back('+');
        }

        // 스택의 top이 x면 pop
        if (stk.top() == x)
        {
            stk.pop();
            result.push_back('-');
        }
        else
        {
            possible = false;
            break;
        }
    }

    if (!possible) 
    {
        cout << "NO\n";
    }
    else
    {
        for (char c : result)
        {
            cout << c << "\n";
        }
    }

    return 0;
}
