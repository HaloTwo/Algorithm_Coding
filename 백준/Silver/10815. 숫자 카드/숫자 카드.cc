#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    unordered_map<int, int> countMap;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        countMap[x]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << countMap[x] << '\n';
    }

    return 0;
}