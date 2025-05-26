#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> sequence(n); // 입력 수열
    vector<char> result;     // 출력 배열
    stack<int> s;            // 스택

    for (int i = 0; i < n; ++i) 
    {
        cin >> sequence[i];
    }

    int current = 1; 

    for (int i = 0; i < n; ++i) 
    {
        int target = sequence[i];

        // 필요한 숫자까지 push
        while (current <= target) 
        {
            s.push(current);
            result.push_back('+');
            current++;
        }

        // top이랑 target 같으면 pop
        if (!s.empty() && s.top() == target) 
        {
            s.pop();
            result.push_back('-');
        }
        else 
        {
            cout << "NO\n";
            return 0;
        }
    }

    // 연산 결과 출력
    for (char c : result) 
    {
        cout << c << '\n';
    }

    return 0;
}
