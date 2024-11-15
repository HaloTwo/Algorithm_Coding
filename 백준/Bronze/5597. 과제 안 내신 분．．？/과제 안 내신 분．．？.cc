#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<bool> check(31, false);
    int x;

    for (int i = 0; i < 28; i++) 
    {
        cin >> x;
        check[x] = true;
    }

    for (int i = 1; i <= 30; i++) 
    {
        if (!check[i]) 
        {
            cout << i << "\n";
        }
    }
}