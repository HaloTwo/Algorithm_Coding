#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int num;

    cin >> num;

    if (num <= 100000 && num % 2024 == 0)
    {
        cout << "Yes";
    }
    else 
    {
        cout << "No";
    }
    return 0;
}