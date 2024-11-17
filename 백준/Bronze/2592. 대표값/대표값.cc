#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> count(1001, 0);  
    int sum = 0;
    int n;

    // 입력
    for (int i = 0; i < 10; i++) 
    {
        cin >> n;
        count[n]++;
        sum += n;
    }

    // 최빈값 찾기
    int maxCount = 0;
    int mode = 0;

    for (int i = 0; i <= 1000; i++) 
    {
        if (count[i] > maxCount) 
        {
            maxCount = count[i];
            mode = i;
        }
    }

    cout << sum / 10 << "\n";
    cout << mode << "\n";

    return 0;
}