#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N);
    vector<int> result(N, -1); 
    stack<int> s;

    for (int i = 0; i < N; i++) cin >> vec[i];


    for (int i = 0; i < N; i++) 
    {
        while (!s.empty() && vec[s.top()] < vec[i]) 
        {
            result[s.top()] = vec[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; i++) cout << result[i] << " ";

    return 0;
}
